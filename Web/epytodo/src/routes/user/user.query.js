import jwt from 'jsonwebtoken';
import bcrypt from 'bcryptjs';
import db from '../../config/db.js';


export const isNewAccount = (res, email, callback) => {
    db.query('SELECT * FROM `user` WHERE email = ?', [email], (error, results, fields) => {
        if (error)
            res.status(500).json({"msg": "Internal server error"});
        else
            callback(results.length === 0);
    });
}

export const register = (res, email, password, name, firstname) => {
    db.query('INSERT INTO `user` (email, password, name, firstname) VALUES (?, ?, ?, ?)',
    [email, password, name, firstname], (error, result, fields) => {
        if (error)
            return res.status(500).json({"msg": "Internal server error"});
        const token = jwt.sign({id: result.insertId}, process.env.SECRET);
        res.status(200).json({"token": token});
    });
}

export const login = (res, email, password, callback) => {
    db.query('SELECT id, password FROM `user` WHERE email = ?', [email], (error, results, fields) => {
        if (error)
            return res.status(500).json({"msg": "Internal server error"});
        if (results.length > 0) {
            // Returns an array but it can't have more than one element due to registration protections
            const dbPassword = results[0].password;

            if (bcrypt.compareSync(password, dbPassword)) {
                const token = jwt.sign(results[0].id, process.env.SECRET);
                res.status(200).json({"token": token});
                callback(true);
            } else {
                callback(false);
            }
        } else {
            callback(false);
        }
    });
}

export const updateUser = (res, userId, email, password, firstname, name) => {
    db.query('UPDATE `user` SET email = ?, password = ?, firstname = ?, name = ? WHERE id = ?',
    [email, password, firstname, name, userId], (error, results, fields) => {
        if (error)
            return res.status(500).json({"msg": "Internal server error"});
        db.query('SELECT * FROM `user` WHERE id = ?', [userId], (error, results, fields) => {
            if (error)
                res.status(500).json({"msg": "Internal server error"});
            else
                res.status(200).json(results[0]);
        });
    });
}

export const deleteUser = (res, userId) => {
    db.query('DELETE FROM `user` WHERE id = ?', [userId], (error, results, fields) => {
        if (error)
            res.status(500).json({"msg": "Internal server error"});
        else
            res.status(200).json({"msg":`Succesfully deleted record number: ${userId}`});
    });
}

export const getUserByParam = (res, param) => {
    db.query('SELECT * FROM `user` WHERE id = ?', [param], (error, results, fields) => {
        if (error) {
            res.status(500).json({"msg": "Internal server error"});
        } else if (results.length > 0) {
            res.status(200).json(results[0]);
        } else {
            db.query('SELECT * FROM `user` WHERE email = ?', [param], (error, results, fields) => {
                if (error)
                    res.status(500).json({"msg": "Internal server error"});
                else if (results.length > 0)
                    res.status(200).json(results[0]);
                else
                    res.status(404).json({"msg": "Not found"});
            });
        }
    });
}

export const getUserTodo = (res, userId) => {
    db.query('SELECT * FROM `todo` WHERE user_id = ?', [userId], (error, results, fields) => {
        if (error)
            res.status(500).json({"msg": "Internal server error"});
        else
            res.status(200).json(results);
    })
}
