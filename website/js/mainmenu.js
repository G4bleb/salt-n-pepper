$(document).ready(function() {
  $( "#generate-game" ).click(function() { //"Génerer une partie" has been clicked
    var animDuration = 500;
    var rightDivWidth = $('#list-games-div').css("width");
    //The button fades away
    $('#generate-game').fadeOut(animDuration);

    $('#list-games-div').animate({//The other div is going to shrink and fade away
      'width' : "-="+rightDivWidth,
      'opacity': '0'
    }, animDuration, function(){
      $(this).remove();//When it's fully shrinked and faded, remove it
    });

    $('#generate-game-div').animate({//The div which is going to become the main one expands
      'width' : "+="+rightDivWidth
    }, animDuration, function() {
      $(this).empty();
      $(this).attr('id', "main-div");//Becomes the main div
      prepareToPlay();//Generate and show a game inside
    });

  });
  $( "#list-games" ).click(function() { //"Rejoindre" has been clicked
    var animDuration = 500;
    var leftDivWidth = $('#generate-game-div').css("width");

    $('#list-games').fadeOut(animDuration);

    $('#generate-game-div').animate({//The other div is going to shrink and fade away
      'width' : "-="+leftDivWidth,
      'opacity': '0'
    }, animDuration, function(){
      $(this).remove();//When it's fully shrinked and faded, remove it
    });

    $('#list-games-div').animate({//The div which is going to become the main one expands
      'width' : "+="+leftDivWidth
    }, animDuration, function() {
      $(this).empty();
      $(this).attr('id', "main-div");//Becomes the main div
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
  $('#main-div').append("<table id='games-list'></table>");
  $('#games-list').append("<tr><th>Parties</th></tr>");
  $.each(data, function(key, val){
    $('#games-list').append("<tr id="+val['id_game']+"><td>Partie numéro "+val['id_game']+"</td></tr>");
    $("#"+val['id_game']).click(function() {
      prepareToPlay(val['id_game']);
    });
  });

}

//------------------------------------------------------------------------------
//--- prepareToPlay -------------------------------------------------------------
//------------------------------------------------------------------------------
// Sets up a game summary in the main div
// \param id_game the id of the game being set up (if we're going to generate one, id_game = -1)
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
