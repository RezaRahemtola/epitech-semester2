CREATE DATABASE IF NOT EXISTS `epytodo`;

USE `epytodo`;

CREATE TABLE IF NOT EXISTS `user`(
    `id` INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    `email` TEXT NOT NULL UNIQUE,
    `password` TEXT NOT NULL,
    `name` TEXT NOT NULL,
    `firstname` TEXT NOT NULL,
    `created_at` DATETIME DEFAULT CURRENT_TIME
);

CREATE TABLE IF NOT EXISTS `todo`(
    `id` INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    `title` TEXT NOT NULL,
    `description` TEXT NOT NULL,
    `created_at` DATETIME DEFAULT CURRENT_TIME,
    `due_time` DATETIME NOT NULL,
    `status` VARCHAR(11) DEFAULT 'not started',
    `user_id` INT UNSIGNED NOT NULL,
    CONSTRAINT check_status CHECK (status IN ('not started', 'todo', 'in progress', 'done')),
    CONSTRAINT fk_user_id
        FOREIGN KEY (`user_id`) REFERENCES `user`(`id`)
        ON DELETE CASCADE
);
