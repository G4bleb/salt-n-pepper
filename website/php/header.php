

<link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.0.13/css/all.css" integrity="sha384-DNOHZ68U8hZfKXOrtjWvjxusGo9WQnrNx2sqG0tfsghAvtVlRW3tvkXWZh58N9jp" crossorigin="anonymous">
<link href="../css/bootstrap.min.css" rel="stylesheet" type="text/css" />
<link href="../css/header.css" rel="stylesheet" type="text/css">
<link href="https://fonts.googleapis.com/css?family=Roboto" rel="stylesheet">
<link href="../css/footer.css" rel="stylesheet" type="text/css">
<link href="../css/default.css" rel="stylesheet" type="text/css">
<link rel="shortcut icon" type="image/x-icon" href="img/favicon.ico"/>
</head>
<body>
  <div id="header">
    <!-- <ul class="list-inline">
      <li class="list-inline-item"><a href="../index.php"><i class="fas fa-home fa-3x" id="home_icon"></i></span></a></li>
      <li class="list-inline-item"><img src="../img/burger.png" class="mx-auto d-block" id="logo"></img></li>
      <li class="list-inline-item"><ul id="navbuttons" class="list-inline"></li>
    </ul> -->
    <a href="../index.php"><i class="fas fa-home fa-3x" id="home_icon"></i></span></a>
    <img src="../img/burger.png" class="mx-auto d-block" id="logo"></img>
    <ul id="navbuttons" class="list-inline">
    <?php require_once 'sessionmanager.php';?>
    <?php if ($sessionValid = checkSession($dbCnx)): ?>
      <li class="list-inline-item"><a href="../login.php?disconnect=y" ><button type="button" class="btn btn-default" id="button_disconnect">Déconnexion</button></a></li>
    <?php else: ?>
        <li class="list-inline-item"><a href="../login.php" ><button type="button" class="btn btn-light" >Connexion</button></a></li>
        <li class="list-inline-item"><a href="../register.php" ><button type="button" class="btn btn-light" >Inscription</button> </a></li>
    <?php endif; ?>
    </ul>
  </div>
