<script src="../js/jquery-3.3.1.min.js"></script>
<script>
function score(time, correctAnswers, totalAnswers){
	// var timeScore = 30 * Math.pow(2, 5 - (time*1000));
	// var questionsScore = totalAnswers * Math.pow(2, totalAnswers - correctAnswers);
	// return timeScore + questionsScore;
	// return Math.sqrt(timeScore*questionsScore);
	// return Math.exp(1/time)/(correctAnswers/totalAnswers);
	// return 1/(correctAnswers/totalAnswers)-Math.exp(time)*(correctAnswers/totalAnswers);
	// return correctAnswers*100-time*25;
	return correctAnswers/(totalAnswers*Math.sqrt(time))*100000;
}
$(document).ready(function() {
	var totalAnswers = 20;
	var times = [5, 10, 20, 30, 40, 50];
	var scores = [5, 10, 15, 20];
	$(document.body).append("Sur "+totalAnswers+" réponses :<br><br>");
	for (var i = 0; i < times.length; i++) {
		for (var j = 0; j < scores.length; j++) {
			finalScore = score(times[i], scores[j], totalAnswers);
			if (finalScore<0) {
				finalScore = 0;
			}
			$(document.body).append(scores[j]+" bonnes réponses en "+times[i]+" secondes donnent "+Math.round(finalScore)+" points<br>");
		}
	}
});
// return sqrt(timeScore * questionsScore);
</script>
