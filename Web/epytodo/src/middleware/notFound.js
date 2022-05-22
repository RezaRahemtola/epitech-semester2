import db from '../config/db.js';


export const checkUserId = (req, res, next) => {
    const id = req.params.id;

    if (id === undefined) {
        res.status(400).json({"msg": "Bad parameter"});
    } else {
        db.query('SELECT * FROM `user` WHERE id = ?', [id], (error, results, fields) => {
            if (error) {
                res.status(500).json({"msg": "Internal server error"});
                return;
            }
            if (results.length > 0)
                next();
            else
                res.status(404).json({"msg": "Not found"});
        });
    }
};

export const checkTodoId = (req, res, next) => {
    const id = req.params.id;

    if (id === undefined) {
        res.status(400).json({"msg": "Bad parameter"});
    } else {
        db.query('SELECT * FROM `todo` WHERE id = ?', [id], (error, results, fields) => {
            if (error) {
                res.status(500).json({"msg": "Internal server error"});
                return;
            }
            if (results.length > 0)
                next();
            else
                res.status(404).json({"msg": "Not found"});
        });
    }
};
