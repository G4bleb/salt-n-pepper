var searchData=
[
  ['r',['r',['../bootstrap_8bundle_8min_8js.html#a1e99b66ec05f848b367484f62b1d1521',1,'r():&#160;bootstrap.bundle.min.js'],['../bootstrap_8min_8js.html#a1e99b66ec05f848b367484f62b1d1521',1,'r():&#160;bootstrap.min.js']]],
  ['ready',['ready',['../mainmenu_8js.html#afd440d398a454dc793ab613d33ff9ac6',1,'ready(function(){var urlParams=new URLSearchParams(window.location.search);var gameId=urlParams.get(&apos;gameId&apos;);if(gameId!=null){prepareToPlay(gameId);}else{$(&quot;#generate-game&quot;).click(function(){var animDuration=500;var rightDivWidth=$(&apos;#list-games-div&apos;).css(&quot;width&quot;);$(&apos;#generate-game&apos;).fadeOut(animDuration);$(&apos;#list-games-div&apos;).animate({ &apos;width&apos;:&quot;-=&quot;+rightDivWidth, &apos;opacity&apos;: &apos;0&apos;}, animDuration, function(){$(this).remove();});$(&apos;#generate-game-div&apos;).animate({ &apos;width&apos;:&quot;+=&quot;+rightDivWidth}, animDuration, function(){$(this).empty();$(this).attr(&apos;id&apos;,&quot;main-div&quot;);prepareToPlay();});});$(&quot;#list-games&quot;).click(function(){var animDuration=500;var leftDivWidth=$(&apos;#generate-game-div&apos;).css(&quot;width&quot;);$(&apos;#list-games&apos;).fadeOut(animDuration);$(&apos;#generate-game-div&apos;).animate({ &apos;width&apos;:&quot;-=&quot;+leftDivWidth, &apos;opacity&apos;: &apos;0&apos;}, animDuration, function(){$(this).remove();});$(&apos;#list-games-div&apos;).animate({ &apos;width&apos;:&quot;+=&quot;+leftDivWidth}, animDuration, function(){$(this).empty();$(this).attr(&apos;id&apos;,&quot;main-div&quot;);ajaxRequest(&apos;GET&apos;, &apos;../php/request.php/gameList&apos;, loadGames);});});}}):&#160;mainmenu.js'],['../play_8js.html#ad6669b38ee2caa9e9f94c9cb3fb3a3c6',1,'ready(function(){var urlParams=new URLSearchParams(window.location.search);var gameId=urlParams.get(&apos;gameId&apos;);currentGame=new Game(gameId);ajaxRequest(&apos;GET&apos;, &apos;../php/request.php/loadQuestions/&apos;+gameId, loadQuestions, currentGame);}):&#160;play.js']]],
  ['rt',['rt',['../bootstrap_8bundle_8min_8js.html#a6ebca04e0374ffa9c0283498d3e582fc',1,'bootstrap.bundle.min.js']]]
];
