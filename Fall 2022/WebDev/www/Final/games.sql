-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: Dec 05, 2022 at 02:21 AM
-- Server version: 8.0.30
-- PHP Version: 7.4.30

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `games`
--

-- --------------------------------------------------------

--
-- Table structure for table `pc`
--

CREATE TABLE `pc` (
  `id` int NOT NULL,
  `name` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `genre` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `console` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `release year` int NOT NULL,
  `rating` decimal(10,0) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `pc`
--

INSERT INTO `pc` (`id`, `name`, `genre`, `console`, `release year`, `rating`) VALUES
(1, 'Counter Strike: Global Offensive', 'Tactical First-person Shooter', 'PC', 2012, '8'),
(2, 'Portal 2', 'Puzzle-platform', 'PC', 2011, '10'),
(3, 'Minecraft', 'Sandbox', 'PC', 2011, '9'),
(4, 'Valorant', 'Tactical First-person Hero Shooter', 'PC', 2020, '9'),
(5, 'Overwatch 2', 'First-person Hero Shooter', 'PC', 2022, '8');

-- --------------------------------------------------------

--
-- Table structure for table `playstation`
--

CREATE TABLE `playstation` (
  `id` int NOT NULL,
  `name` varchar(128) COLLATE utf8mb4_general_ci NOT NULL,
  `genre` varchar(128) COLLATE utf8mb4_general_ci NOT NULL,
  `console` varchar(128) COLLATE utf8mb4_general_ci NOT NULL,
  `release year` int NOT NULL,
  `rating` decimal(10,0) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `playstation`
--

INSERT INTO `playstation` (`id`, `name`, `genre`, `console`, `release year`, `rating`) VALUES
(1, 'God of War Ragnarok', 'Action-adventure', 'PS4/PS5', 2022, '10'),
(2, 'Uncharted 4: A Thief\'s End', 'Action-adventure', 'PS4/PS5', 2016, '9'),
(3, 'Elden Ring', 'Action RPG', 'PS4/PS5', 2022, '10'),
(4, 'DOOM Eternal', 'First-person Shooter', 'PS4/PS5', 2020, '9'),
(5, 'Grand Theft Auto V', 'Open-world Action', 'PS3/PS4/PS5', 2013, '10');

-- --------------------------------------------------------

--
-- Table structure for table `switch`
--

CREATE TABLE `switch` (
  `id` int NOT NULL,
  `name` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `genre` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `console` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `release year` int NOT NULL,
  `rating` decimal(10,0) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `switch`
--

INSERT INTO `switch` (`id`, `name`, `genre`, `console`, `release year`, `rating`) VALUES
(1, 'Super Mario Odyssey', 'Platforming', 'Nintendo Switch', 2017, '10'),
(2, 'The Legend of Zelda: Breath of the Wild', 'Open-world Action-adventure', 'Nintendo Switch', 2017, '10'),
(3, 'Animal Crossing: New Horizons', 'Sim', 'Nintendo Switch', 2020, '8'),
(4, 'Mario Kart 8 Deluxe', 'Racing', 'Nintendo Switch', 2017, '9'),
(5, 'Super Smash Bros. Ultimate', 'Fighting', 'Nintendo Switch', 2018, '9');

-- --------------------------------------------------------

--
-- Table structure for table `xbox`
--

CREATE TABLE `xbox` (
  `id` int NOT NULL,
  `name` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `genre` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `console` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `release year` int NOT NULL,
  `rating` decimal(10,0) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `xbox`
--

INSERT INTO `xbox` (`id`, `name`, `genre`, `console`, `release year`, `rating`) VALUES
(1, 'Halo Infinite', 'First-person Shooter', 'Series X/Series S/One', 2021, '9'),
(2, 'Forza Horizon 5', 'Racing', 'Series X/Series S/One', 2021, '10'),
(3, 'Gears 5', 'Third-person Shooter', 'Series X/Series S/One', 2019, '8'),
(4, 'Assassin\'s Creed Valhalla', 'Action RPG', 'Series X/Series S/One', 2018, '8'),
(5, 'Hitman 3', 'Stealth', 'Series X/Series S/One', 2021, '9');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `pc`
--
ALTER TABLE `pc`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `playstation`
--
ALTER TABLE `playstation`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `switch`
--
ALTER TABLE `switch`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `xbox`
--
ALTER TABLE `xbox`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `pc`
--
ALTER TABLE `pc`
  MODIFY `id` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT for table `playstation`
--
ALTER TABLE `playstation`
  MODIFY `id` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT for table `switch`
--
ALTER TABLE `switch`
  MODIFY `id` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT for table `xbox`
--
ALTER TABLE `xbox`
  MODIFY `id` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
