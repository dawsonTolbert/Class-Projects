<?php // villagers.php
  $host = 'localhost'; 
  $data = 'villagers'; 
  $user = 'root'; 
  $pass = 'mysql';
  $chrs = 'utf8mb4';
  $attr = "mysql:host=$host;dbname=$data;charset=$chrs";
  $opts =
  [
    PDO::ATTR_ERRMODE            => PDO::ERRMODE_EXCEPTION,
    PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC,
    PDO::ATTR_EMULATE_PREPARES   => false,
  ];

  try {
    $pdo = new PDO($attr, $user, $pass, $opts);
  }
  catch (PDOException $e) {
    throw new PDOException($e->getMessage(), (int)$e->getCode());
  }

  if (isset($_POST['delete']) && isset($_POST['vname'])) {
    $vname   = $pdo->quote($_POST['vname']);
    $query  = "DELETE FROM vdata WHERE vname=$vname";
    $result = $pdo->query($query);
  }
  if (isset($_POST['vname'])   &&
      isset($_POST['species']) &&
      isset($_POST['month']) &&
      isset($_POST['day']) &&
      isset($_POST['diet'])) {
    $vname     = $pdo->quote($_POST['vname']);
    $species   = $pdo->quote($_POST['species']);
    $month     = $pdo->quote($_POST['month']);
    $day       = $pdo->quote($_POST['day']);
    $diet      = $pdo->quote($_POST['diet']);
    
    $query    = "INSERT INTO vdata VALUES" .
      "($vname, $species, $month, $day, $diet)";
    $result = $pdo->query($query);
  }

  echo <<<_END
  <form action="villagers.php" method="post" autocomplete="off">
  <fieldset><legend>Add New Villager</legend>
  <pre>
        Name <input type="text" name="vname" required>

     Species<input type="radio" name="species" value="Wolf" required>Wolf     <input type="radio" name="species" value="Cat">Cat       <input type="radio" name="species" value="Kangaroo">Kangaroo
            <input type="radio" name="species" value="Elephant">Elephant <input type="radio" name="species" value="Alligator">Alligator <input type="radio" name="species" value="Dog">Dog

    Birthday <select name="month">
    <option value="Jan">Jan</option>
    <option value="Feb">Feb</option>
    <option value="Mar">Mar</option>
    <option value="Apr">Apr</option>
    <option value="May">May</option>
    <option value="Jun">Jun</option>
    <option value="Jul">Jul</option>
    <option value="Aug">Aug</option>
    <option value="Sep">Sep</option>
    <option value="Oct">Oct</option>
    <option value="Nov">Nov</option>
    <option value="Dec">Dec</option></select><select name="day"><option value="1">1</option>
    <option value="2">2</option>
    <option value="3">3</option>
    <option value="4">4</option>
    <option value="5">5</option>
    <option value="6">6</option>
    <option value="7">7</option>
    <option value="8">8</option>
    <option value="9">9</option>
    <option value="10">10</option>
    <option value="11">11</option>
    <option value="12">12</option>
    <option value="13">13</option>
    <option value="14">14</option>
    <option value="15">15</option>
    <option value="16">16</option>
    <option value="17">17</option>
    <option value="18">18</option>
    <option value="19">19</option>
    <option value="20">20</option>
    <option value="21">21</option>
    <option value="22">22</option>
    <option value="23">23</option>
    <option value="24">24</option>
    <option value="25">25</option>
    <option value="26">26</option>
    <option value="27">27</option>
    <option value="28">28</option>
    <option value="29">29</option>
    <option value="30">30</option></select>

        Diet <input type="hidden" name="diet" value="No"><input type="checkbox" name="diet" value="Yes">Special diet

             <input type="submit" value="Villager Moved In">
  </pre></fieldset></form>

  <fieldset><legend>Roster of Villagers</legend>
_END;

  $query  = "SELECT * FROM vdata";
  $result = $pdo->query($query);

  while ($row = $result->fetch()) {
    $r0 = htmlspecialchars($row['vname']);
    $r1 = htmlspecialchars($row['species']);
    $r2 = htmlspecialchars($row['month']);
    $r3 = htmlspecialchars($row['day']);
    $r4 = htmlspecialchars($row['diet']);
    
    echo <<<_END
  <pre><table><tr><td width="225"><table><tr><td width="125">Name:</td><td width="100">$r0</td></tr>
  <tr><td>Species:</td><td>$r1</td></tr>
  <tr><td>Birthday:</td><td>$r2 $r3</td></tr>
  <tr><td>Special diet: </td><td>$r4</td></tr></table>
  
  <td width=100"><br><br><form action='villagers.php' method='post'>
  <input type='hidden' name='delete' value='yes'>
  <input type='hidden' name='vname' value='$r0'>
  <input type='submit' value='Villager Moved Out'></td></tr></table></pre></form>
  _END;
  }
?>