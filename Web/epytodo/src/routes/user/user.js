import { Router } from 'express';
import bcrypt from 'bcryptjs';
import { auth } from '../../middleware/auth.js';
import { checkUserId } from '../../middleware/notFound.js';
import { updateUser, deleteUser, getUserByParam, getUserTodo } from './user.query.js';


const router = Router();

router.get("/user", auth, (req, res) => {
    const userId = req.userId;

    if (userId === undefined)
        return res.status(500).json({"msg": "Internal server error"});
    getUserByParam(res, userId);
});

router.get("/user/todos", auth, (req, res) => {
    const userId = req.userId;

    if (userId === undefined)
        return res.status(500).json({"msg": "Internal server error"});
    getUserTodo(res, userId);
});

router.get("/users/:param", auth, (req, res) => {
    const param = req.params.param;

    if (param === undefined)
        return res.status(400).json({"msg": "Bad parameter"});
    getUserByParam(res, param);
});

router.put("/users/:id", auth, checkUserId, (req, res) => {
    const userId = req.params.id;
    const email = req.body["email"];
    const password = req.body["password"];
    const firstname = req.body["firstname"];
    const name = req.body["name"];

    if (email === undefined || password === undefined || firstname === undefined || name === undefined)
        return res.status(400).json({"msg": "Bad parameter"});
    const hashedPassword = bcrypt.hashSync(password);
    updateUser(res, userId, email, hashedPassword, firstname, name);
});

router.delete("/users/:id", auth, checkUserId, (req, res) => {
    const userId = req.params.id;

    deleteUser(res, userId);
});

export default router;
