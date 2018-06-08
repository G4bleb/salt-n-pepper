class Game{
  constructor(id, questions, propositions) {
    this.id = id;
    this.questions = questions;
    this.currentQuestionNb = 0;
    this.propositions = propositions;
    // this.currentPropositionNb = 0;
    this.totalAnswers=0;
    this.correctAnswers=0;
    this.startTime=$.now();
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
  alert(currentGame.correctAnswers+'/'+currentGame.totalAnswers+" Starting time :"+currentGame.startTime);
}
