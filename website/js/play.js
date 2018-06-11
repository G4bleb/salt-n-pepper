class Game{
  constructor(id, questions, propositions) {
    this.id = id;
    this.questions = questions;
    this.currentQuestionNb = 0;
    this.propositions = propositions;
    this.totalAnswers=0;
    this.correctAnswers=0;
    this.startTime=$.now();
  }
  calculateScore(){
    return (this.correctAnswers/this.totalAnswers)*(1/($.now()-this.startTime))*100000000;
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
  ajaxRequest('GET', '../php/request.php/loadPropositions/'+currentGame.questions[0]['id_topic']+'/'+currentGame.questions[0]['num_question'], loadPropositions, currentGame);
}

function loadPropositions(ajaxResponse, currentGame){
  // Parse JSON response.
  currentGame.propositions = JSON.parse(ajaxResponse);
  // currentGame.totalAnswers += currentGame.propositions.length;
  setupProposition(currentGame, 0);
  // console.log(propositions);
}

function setupQuestion(currentGame, index){
  // console.log("QuestionIndex : "+index);
  ajaxRequest('GET', '../php/request.php/loadPropositions/'+currentGame.questions[index]['id_topic']+'/'+currentGame.questions[index]['num_question'], loadPropositions, currentGame);
  $('#question').html(currentGame.questions[index]['main_question']);
  $('#answer1').html(currentGame.questions[index]['answer1']);
  $('#answer2').html(currentGame.questions[index]['answer2']);
}

function setupProposition(currentGame, index){
  // console.log("PropositionIndex : "+index);

  currentGame.totalAnswers++;
  console.log("New answer : "+currentGame.totalAnswers);
  $('#proposition').html(currentGame.propositions[index]['main_proposition']);
  for (var i = 1; i <= 3; i++) {
    console.log('binding answer'+i);
    $('#answer'+i).off('click').click(function(){
      // console.log("checkAnswer "+$(this).attr('id').charAt($(this).attr('id').length - 1));
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
    score = Math.round(currentGame.calculateScore());
    $('#main-div').append('<h2><span class="badge badge-warning">Score : '+score+'</span></h2>');
    // alert(currentGame.correctAnswers+'/'+currentGame.totalAnswers+" Starting time :"+currentGame.startTime);
    ajaxRequest('POST', '../php/request.php/addScore/'+currentGame.id, checkHighscore, undefined, 'score=' + score);
    $('#main-div').append('<h1><button id="back-to-mainmenu" class="bigbutton btn btn-primary">Menu principal</button></h1>');
    $('#main-div').fadeIn(delay);
  },delay);
  // window.location.replace("results.php");
}

function checkHighscore(ajaxResponse){
  console.log(ajaxResponse);
  // Parse JSON response.
  if (JSON.parse(ajaxResponse)) {
    $('#main-div').append('<h1>Nouveau record !</h1>');
  }
}
