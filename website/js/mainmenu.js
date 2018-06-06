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
      prepareToPlay(1);
      // ajaxRequest('GET', '../php/request.php/gamelist', loadGames);
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
  console.log(data);
  // Load comments.

  jQuery.each(data, function(key, val){
    $('#main-div').append("<table><tr id="+val.id_game+"><td>Partie numéro "+val.id_game+"</td></tr></table>");
    $("#"+val.id_game).click(function() {
      prepareToPlay(val.id_game);
    });
    // alert(val.id_game);
  });
}

function prepareToPlay(id_game){
  console.log("Preparing to play");
  if (!($('#main-div').is(':empty'))){
    $('#main-div').children().fadeOut(250, function() {
      $(this).empty()
    });
  }
  
}
