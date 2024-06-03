<?php // album.php
  $host = 'localhost';    // shouldn't need to change
  $data = 'publications';        // Change as necessary
  $user = 'dawson';         // Change as necessary
  $pass = 'dawson';         // Change as necessary
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

  if (isset($_POST['delete']) && isset($_POST['title'])) {
    $title   = $pdo->quote($_POST['title']);
    $query  = "DELETE FROM albums WHERE title=$title";
    $result = $pdo->query($query);
  }

  if (isset($_POST['artist'])   &&
      isset($_POST['title'])    &&
      isset($_POST['year'])) {
    $artist   = $pdo->quote($_POST['artist']);
    $title    = $pdo->quote($_POST['title']);
    $year     = $pdo->quote($_POST['year']);
    
    $query    = "INSERT INTO albums VALUES" .
      "($artist, $title, $year)";
    $result = $pdo->query($query);
  }

  echo <<<_END
  <form action="album.php" method="post"><pre>
    Artist <input type="text" name="artist">
     Title <input type="text" name="title">
      Year <input type="text" name="year">
           <input type="submit" value="ADD ALBUM">
  </pre></form>
_END;

  $query  = "SELECT * FROM albums";
  $result = $pdo->query($query);

  while ($row = $result->fetch()) {
    // create temp strings w/security
    $r0 = htmlspecialchars($row['artist']);
    $r1 = htmlspecialchars($row['title']);
    $r2 = htmlspecialchars($row['year']);
    
    // output record data and delete button
    echo <<<_END
  <pre>
    Artist $r0
     Title $r1
      Year $r2
  </pre>
  <form action='album.php' method='post'>
  <input type='hidden' name='delete' value='yes'>
  <input type='hidden' name='title' value='$r1'>
  <input type='submit' value='delete album'></form>
_END;
  }
?>