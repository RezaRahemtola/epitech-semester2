import db from '../../config/db.js';


export const getAllTodos = (res) => {
    db.query('SELECT * FROM `todo`', (error, results, fields) => {
        if (error)
            res.status(500).json({"msg": "Internal server error"});
        else
            res.status(200).json(results);
    });
}

export const getTodoById = (res, id) => {
    db.query('SELECT * FROM `todo` WHERE id = ?', [id], (error, results, fields) => {
        if (error)
            res.status(500).json({"msg": "Internal server error"});
        else
            res.status(200).json(results[0]);
    });
}

export const createTodo = (res, title, description, due_time, status, user_id) => {
    db.query('INSERT INTO `todo` (title, description, due_time, status, user_id) VALUES (?, ?, ?, ?, ?)',
    [title, description, due_time, status, user_id], (error, results, fields) => {
        if (error) {
            res.status(500).json({"msg": "Internal server error"});
            return;
        }
        const todoId = results["insertId"];

        db.query('SELECT * FROM `todo` WHERE id = ?', [todoId], (error, results, fields) => {
            if (error)
                res.status(500).json({"msg": "Internal server error"});
            else
                res.status(200).json(results[0]);
        });
    });
}

export const updateTodo = (res, todoId, title, description, due_time, status, user_id) => {
    db.query('UPDATE `todo` SET title = ?, description = ?, due_time = ?, status = ?, user_id = ? WHERE id = ?',
    [title, description, due_time, status, user_id, todoId], (error, results, fields) => {
        if (error) {
            res.status(500).json({"msg": "Internal server error"});
            return;
        }
        db.query('SELECT title, description, due_time, user_id, status FROM `todo` WHERE id = ?', [todoId], (error, results, fields) => {
            if (error)
                res.status(500).json({"msg": "Internal server error"});
            else
                res.status(200).json(results[0]);
        });
    });
}

export const deleteTodo = (res, todoId) => {
    db.query('DELETE FROM `todo` WHERE id = ?', [todoId], (error, results, fields) => {
        if (error)
            res.status(500).json({"msg": "Internal server error"});
        else
            res.status(200).json({"msg": `Succesfully deleted record number: ${todoId}`});
    });
}
