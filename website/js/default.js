//------------------------------------------------------------------------------
//--- emptyMainDiv -------------------------------------------------------------
//------------------------------------------------------------------------------
// Empties the main div, whose id is "main-div"
// \returns delay the time the div will take to empty
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
