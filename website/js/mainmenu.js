$(document).ready(function() {
  $( "#generate-game" ).click(function() {
    var animDuration = 500;
    var rightDivWidth = $('#list-games-div').css("width");

    $('#generate-game').fadeOut(animDuration);

    $('#list-games-div').animate({
      'width' : "-="+rightDivWidth,
      'opacity': '0'
    }, animDuration, function(){
      $(this).remove();
    });

    $('#generate-game-div').animate({
      'width' : "+="+rightDivWidth
    }, animDuration, function() {
      $(this).empty();
      $(this).attr('id', "main-div");
      prepareToPlay();
    });

  });
  $( "#list-games" ).click(function() {
    var animDuration = 500;
    var leftDivWidth = $('#generate-game-div').css("width");

    $('#list-games').fadeOut(animDuration);

    $('#generate-game-div').animate({
      'width' : "-="+leftDivWidth,
      'opacity': '0'
    }, animDuration, function(){
      $(this).remove();
    });

    $('#list-games-div').animate({
      'width' : "+="+leftDivWidth
    }, animDuration, function() {
      $(this).empty();
      $(this).attr('id', "main-div");
      ajaxRequest('GET', '../php/request.php/gamelist', loadGames);
    });
  });
});

//------------------------------------------------------------------------------
//--- loadGames -------------------------------------------------------------
//------------------------------------------------------------------------------
// Load the games list.
// \param ajaxResponse The data received via the Ajax request.
function loadGames(ajaxResponse){
  // Parse JSON response.
  var data = JSON.parse(ajaxResponse);
  // console.log(data);
  // Load comments.
  $('#main-div').append("<table id='games-list'></table>");
  $('#games-list').append("<tr><th>Parties</th></tr>");
  $.each(data, function(key, val){
    // alert($.type(val));
    $('#games-list').append("<tr id="+val.id_game+"><td>Partie numéro "+val.id_game+"</td></tr>");
    $("#"+val.id_game).click(function() {
      prepareToPlay(val.id_game);
    });
  });

}

function emptyMainDiv(){
  var delay = 0;
  if (!($('#main-div').is(':empty'))){
    delay = 150;
    $('#main-div').children().fadeOut(delay, function() {
      $(this).empty();
    });
  }
  return delay;
}

function prepareToPlay(id_game = -1){
  var delay = emptyMainDiv();
  console.log("Preparing to play game number "+id_game);

  setTimeout(function() {
    ajaxRequest('GET', '../php/request.php/loadGame/'+id_game, function(ajaxResponse){
      var data = JSON.parse(ajaxResponse);
      $('#main-div').append("<table id='questions-list'></table>");
      $('#questions-list').append("<tr><th>Question</th><th>Thème</th></tr>");
      $.each(data, function(key, val){
        $('#questions-list').append("<tr><td>"+val.main_question+"</td><td>"+val.topic_name+"</td></tr>");
      });
      $('#main-div').append('<h1><a href="play.php?gameId='+data[0].id_game+'"><button id="start-game" class="bigbutton btn btn-primary" >Jouer</button></h1>');
    });
  }, delay);
}
