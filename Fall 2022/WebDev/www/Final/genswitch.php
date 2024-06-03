<?php // xbox.php
  $host = 'localhost';    // shouldn't need to change
  $data = 'games';        // Change as necessary
  $user = 'root';         // Change as necessary
  $pass = 'mysql';         // Change as necessary
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

  $result = $pdo->query("SELECT * FROM switch ORDER BY id ASC LIMIT 1");
  $row = $result->fetch();
  $smallestId = htmlspecialchars($row['id']);
  
  $result  = $pdo->query("SELECT * FROM switch ORDER BY id DESC LIMIT 1");
  $row = $result->fetch();
  $biggestId = htmlspecialchars($row['id']);

  $randomId = mt_rand($smallestId, $biggestId);
  $result = $pdo->query("SELECT * FROM switch WHERE id='$randomId'");

  $row = $result->fetch();
  // create temp strings w/security
  $r0 = htmlspecialchars($row['name']);
  $r1 = htmlspecialchars($row['genre']);
  $r2 = htmlspecialchars($row['console']);
  $r3 = htmlspecialchars($row['release year']);
  $r4 = htmlspecialchars($row['rating']);
    
  // output record data and delete button
  echo <<<_END
  <pre>
      Name $r0
     Genre $r1
   Console $r2
      Year $r3
    Rating $r4
  </pre>
  _END;
?>