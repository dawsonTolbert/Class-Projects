<?php // album.php
  $host = 'localhost';    // shouldn't need to change
  $data = 'publications';        // Change as necessary
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

  if (isset($_POST['delete']) && isset($_POST['title'])) {
    $title   = $pdo->quote($_POST['title']);
    $query  = "DELETE FROM albums WHERE title=$title";
    $result = $pdo->query($query);
  }

  if (isset($_POST['artist'])   &&
      isset($_POST['title'])    &&
      isset($_POST['year'])     &&
      isset($_POST['rating'])   &&
      isset($_POST['stock'])) {
    $artist   = $pdo->quote($_POST['artist']);
    $title    = $pdo->quote($_POST['title']);
    $year     = $pdo->quote($_POST['year']);
    $rating   = $pdo->quote($_POST['rating']);
    if ($_POST['stock'] == 'true') {
      $stock  = "Yes";
    }
    else {
      $stock  = "No";
    }
    
    $query    = "INSERT INTO albums VALUES" .
      "($artist, $title, $year, $rating, '$stock')";
    $result = $pdo->query($query);
  }

  echo <<<_END
  <form action="album.php" method="post"><pre>
    Artist <input type="text" name="artist">
     Title <input type="text" name="title">
      Year <input type="text" name="year">
    Rating <input type="range" name="rating" min="1" max="5">
  In Stock <input type="checkbox" name="stock" value="true" checked="checked">
           <input type="submit" value="ADD ALBUM"><input type="reset" value="RESET">
  </pre></form>
_END;

  $query  = "SELECT * FROM albums";
  $result = $pdo->query($query);

  while ($row = $result->fetch()) {
    // create temp strings w/security
    $r0 = htmlspecialchars($row['artist']);
    $r1 = htmlspecialchars($row['title']);
    $r2 = htmlspecialchars($row['year']);
    $r3 = htmlspecialchars($row['rating']);
    $r4 = htmlspecialchars($row['stock']);
    
    // output record data and delete button
    echo <<<_END
  <pre>
    Artist $r0
     Title $r1
      Year $r2
    Rating $r3
  In Stock $r4
  </pre>
  <form action='album.php' method='post'>
  <input type='hidden' name='delete' value='yes'>
  <input type='hidden' name='title' value='$r1'>
  <input type='submit' value='delete album'></form>
_END;
  }
?>