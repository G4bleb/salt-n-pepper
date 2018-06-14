//Code to prevent the user from submitting the form with incorrect passwords
$('#password, #confirm_password').on('keyup', function () {
  if ($('#password').val() == $('#confirm_password').val()) {
    $('#confirmed').html('Mots de passe valides').css('color', 'green');
    $("input[type=submit][name='register']").removeAttr("disabled");
  } else{
    $('#confirmed').html('Veuillez entrer des mots de passes correspondants').css('color', 'red');
    $("input[type=submit][name='register']").attr("disabled", "disabled");
  }
  if ($('#password').val() == ""){
    $('#confirmed').html('Veuillez entrer un mot de passe').css('color', 'red');
    $("input[type=submit][name='register']").attr("disabled", "disabled");
  }
});
