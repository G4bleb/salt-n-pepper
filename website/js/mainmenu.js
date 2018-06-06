$(document).ready(function() {
  $( "#generate-game" ).click(function() {
    // ajaxRequest('GET', '../php/request.php', );
  });
  $( "#list-games" ).click(function() {
    var animDuration = 500;
    var leftDivWidth = $('#generate-game-div').css("width");

    $('#list-games').fadeOut(animDuration);
    $('#generate-game-div').animate({
      'width' : "-="+leftDivWidth,
      'opacity': '0'
    }, animDuration, function(){$('#generate-game-div').remove();});
    $('#list-games-div').animate({
      'width' : "+="+leftDivWidth
    }, animDuration, function() {
      $('#list-games-div').attr('id', "main-div");
      ajaxRequest('GET', '../php/request.php/gamelist', loadGames);
    });
  });
});

//------------------------------------------------------------------------------
//--- loadGames -------------------------------------------------------------
//------------------------------------------------------------------------------
// Load the games list.
// \param ajaxResponse The data received via the Ajax request.
function loadGames(ajaxResponse)
{
  var comments;
  var data;
  var text;
  var div;

  // Parse JSON response.
  data = JSON.parse(ajaxResponse);
  console.log(data);
  // Load comments.

  jQuery.each(data, function(key, val){
    // alert(val.id_game);
  });

  comments = $('#comments');
  comments.html('');
  for (var i = 0; i < data.length; i++)
  {
    // Display comment.
    div = document.createElement('div');
    text = '<div class="panel panel-default"><div class="panel-body">';
    text += data[i].comment;
    text += '<span id=delete-' + data[i].id + ' class="glyphicon ';
    text += 'glyphicon-trash pull-right"></span>';
    text += '</div></div>';
    div.innerHTML = text;
    comments.append(div);


    // Add send callback on comment
    $("#comments-add").show();
    $('#add').unbind('click').click(
      function (event)
      {
        var comment;
        var photoId;

        comment = $('#comment-add').val();
        photoId = $('#photo').attr('photoid');
        event.preventDefault();
        if (comment != '' && photoId != undefined)
        {
          ajaxRequest('POST', 'php/request.php/comments/', function ()
          {
            ajaxRequest('GET', 'php/request.php/comments/' + photoId, loadComments);
          }, 'id=' + photoId + '&comment=' + comment);
        }
      });

      // Add delete callback on comment
      $('#delete-' + data[i].id).unbind('click').click(
        function (event)
        {
          var photoId;
          var id;

          photoId = $('#photo').attr('photoid');
          id = event.target.id.substr(7);
          event.preventDefault();
          if (id != undefined && photoId != undefined)
          {
            ajaxRequest('DELETE', 'php/request.php/comments/' + id, function ()
            {
              ajaxRequest('GET', 'php/request.php/comments/' + photoId, loadComments);
            });
          }
        });
      }
    }
