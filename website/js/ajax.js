'use strict';
/**
* @file ajax.js
* @brief A file for ajaxRequest functions, and error handling
* @author Thibaut Napoléon, Gabriel Lebis
* @date 2018-06-15
*/
/**
* Performs an Ajax request
* @param type The type of the request (GET, DELETE, POST, PUT)
* @param request The request with the data
* @param callback The callback to call where the request is successful
* @param additionnalCallbackParameter a second callback parameter (if needed)
* @param data The data associated with the request
*/
function ajaxRequest(type, request, callback, additionnalCallbackParameter = undefined, data = null) {
  var xhr;

  // Create XML HTTP request.
  xhr = new XMLHttpRequest();
  if (data != null && (type == 'GET' || type == 'POST' || type == 'DELETE')) {
    request += '?' + data;
  }
  console.log('request : '+request)
  xhr.open(type, request, true);

  xhr.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');

  // Add the onload function.
  xhr.onload = function () {
    console.log(xhr.status);
    switch (xhr.status) {
      case 200:
      case 201:
        console.log(xhr.responseText);
        $('#errors').hide();
        callback(xhr.responseText, additionnalCallbackParameter);
        break;
      case 401:
      case 403:
        httpErrors(xhr.status);
        authentication();
        break;
      default:
        httpErrors(xhr.status);
    }
  };

  // Send XML HTTP request.
  xhr.send(data);
}

/**
* Displays a message corresponding to an Http error code
* @param errorNumber the error code
*/
function httpErrors(errorNumber) {
  var text = '<span class="glyphicon glyphicon-exclamation-sign"></span>';
  switch (errorNumber) {
    case 400:
      // Bad request.
      text += '<strong> Requête incorrecte</strong>';
      break;
    case 401:
      // Unauthorized.
      text += '<strong> Veuillez vous authentifier</strong>';
      break;
    case 403:
      // Forbidden.
      text += '<strong> Accès refusé</strong>';
      break;
    case 404:
      // Ressource not found.
      text += '<strong> Page non trouvée</strong>';
      break;
    case 500:
      // Internal server error.
      text += '<strong> Erreur interne du serveur</strong>';
      break;
    case 503:
      // Service unavailable.
      text += '<strong> Service indisponible</strong>';
      break;
    default:
      text += '<strong> HTTP erreur ' + errorNumber + '</strong>';
      break;
  }
  $('#errors').html(text);
  $('#errors').show();
}
