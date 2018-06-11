class Game{
  constructor(id, questions, propositions) {
    this.id = id;
    this.questions = questions;
    this.currentQuestionNb = 0;
    this.propositions = propositions;
    this.totalAnswers=0;
    this.correctAnswers=0;
    this.startTime=$.now();
    this.setuped = false;
  }
  calculateScore(){
    return this.correctAnswers/(this.totalAnswers*Math.sqrt(($.now()-this.startTime)/1000))*100000;
  }
}

$(document).ready(function() {
  var urlParams = new URLSearchParams(window.location.search);
  var gameId = urlParams.get('gameId');
  var questions, propositions;
  currentGame = new Game(gameId, questions, propositions);
  ajaxRequest('GET', '../php/request.php/loadQuestions/'+gameId, loadQuestions, currentGame);
});

function loadQuestions(ajaxResponse, currentGame){
  // Parse JSON response.
  currentGame.questions = JSON.parse(ajaxResponse);
  setupQuestion(currentGame, 0);
}

function loadPropositions(ajaxResponse, currentGame){
  // Parse JSON response.
  currentGame.propositions = JSON.parse(ajaxResponse);
  setupProposition(currentGame, 0);
}

function setupQuestion(currentGame, index){
  var delay = 100;
  if (!currentGame.setuped) {
    delay = 0;
  }
  // console.log("QuestionIndex : "+index);
  ajaxRequest('GET', '../php/request.php/loadPropositions/'+currentGame.questions[index]['id_topic']+'/'+currentGame.questions[index]['num_question'], loadPropositions, currentGame);
  $('#question').fadeOut(delay, function(){
    $(this).html(currentGame.questions[index]['main_question']);
    $(this).fadeIn(delay);
  });
  $('#answer1').fadeOut(delay, function(){
    $(this).html(currentGame.questions[index]['answer1']);
    $(this).fadeIn(delay);
  });
  $('#answer2').fadeOut(delay, function(){
    $(this).html(currentGame.questions[index]['answer2']);
    $(this).fadeIn(delay);
  });
}

function setupProposition(currentGame, index){
  // console.log("PropositionIndex : "+index);
  var propositionDelay = 50;
  if (!currentGame.setuped) {
    propositionDelay = 0;
  }
  currentGame.totalAnswers++;
  console.log("Total answers : "+currentGame.totalAnswers);
  $('#proposition').fadeOut(propositionDelay, function(){
    $(this).html(currentGame.propositions[index]['main_proposition']);
    $(this).fadeIn(propositionDelay);
    currentGame.setuped=true;
  });
  for (var i = 1; i <= 3; i++) {
    console.log('binding answer'+i);
    $('#answer'+i).off('click').click(function(){
      $(this).prop('disabled', true);
      $(this).fadeOut(100, function(){
        $(this).fadeIn(100, function(){
          $(this).prop('disabled', false);
        });
      });
      checkAnswer(currentGame, $(this).attr('id').charAt($(this).attr('id').length - 1), index);
      if (index+1 < currentGame.propositions.length){
        setupProposition(currentGame, index+1);
      }else{
        currentGame.currentQuestionNb++;
        if (currentGame.currentQuestionNb < currentGame.questions.length) {
          setupQuestion(currentGame, currentGame.currentQuestionNb);
        }else{
          endGame(currentGame);
        }
      }
    });
  }
}

function checkAnswer(currentGame, numberAnswered, propositionIndex){
  console.log(currentGame.propositions[propositionIndex]['answer_nb']+" equal to "+numberAnswered);
  if (currentGame.propositions[propositionIndex]['answer_nb'] == numberAnswered) {
    currentGame.correctAnswers++;
  }
}

function endGame(currentGame){
  var delay = emptyMainDiv(150);
  setTimeout(function(){
    $('#main-div').hide();
    $('#main-div').append('<ul id="score-features" class="list-inline"><ul>');
    $('#score-features').append('<li class="list-inline-item"><h2><span id="mark" class="badge badge-warning"></span></h2></li>');
    $('#score-features').append('<li class="list-inline-item"><h2><span id="time" class="badge badge-warning"></span></h2></li>');
    $('#mark').html(currentGame.correctAnswers+"/"+currentGame.totalAnswers);
    $('#time').html((($.now()-currentGame.startTime)/1000).toFixed(2)+" secondes");
    var score = Math.round(currentGame.calculateScore());
    $('#main-div').append('<h2><span class="badge badge-warning">Score : '+score+'</span></h2>');
    // alert(currentGame.correctAnswers+'/'+currentGame.totalAnswers+" Starting time :"+currentGame.startTime);
    ajaxRequest('POST', '../php/request.php/addScore/'+currentGame.id, checkHighscore, undefined, 'score=' + score);
    setTimeout(function() {
      $('#main-div').append('<h1><a href="mainmenu.php"><button id="back-to-mainmenu" class="bigbutton btn btn-primary">Menu principal</button></a></h1>');
    }, delay);
    $('#main-div').fadeIn(delay);
  },delay);
  // window.location.replace("results.php");
}

function checkHighscore(ajaxResponse){
  console.log(ajaxResponse);
  // Parse JSON response.
  if (JSON.parse(ajaxResponse)) {
    $('#main-div').append('<div class="alert alert-success" role="alert"><h3>Nouveau record !</h3></div>');
  }
}
