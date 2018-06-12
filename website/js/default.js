//------------------------------------------------------------------------------
//--- emptyMainDiv -------------------------------------------------------------
//------------------------------------------------------------------------------
// Empties the main div, whose id is "main-div"
// \param delay the maximum time that could be taken to empty the div
// \returns delay the time the div will take to empty
function emptyMainDiv(delay = 150){
  var emptyingDelay = 0;
  if (!($('#main-div').is(':empty'))){
    emptyingDelay = delay;
    $('#main-div').children().fadeOut(delay, function() {
      $(this).empty();
    });
  }
  return emptyingDelay;
}
