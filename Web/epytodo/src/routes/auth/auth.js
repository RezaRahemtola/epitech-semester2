import { Router } from 'express';
import bcrypt from 'bcryptjs';
import { isNewAccount, register, login } from '../user/user.query.js';


const router = Router();

router.post('/register', (req, res) => {
    const email = req.body["email"];
    const name = req.body["name"];
    const firstname = req.body["firstname"];
    const password = req.body["password"];

    if (email === undefined || name === undefined || firstname === undefined || password === undefined)
        return res.status(400).json({"msg": "Bad parameter"});
    const hashedPassword = bcrypt.hashSync(password);
    isNewAccount(res, email, (newAccount) => {
        if (!newAccount)
            res.status(409).json({"msg": "Account already exists"});
        else
            register(res, email, hashedPassword, name, firstname);
    });
});

router.post('/login', (req, res) => {
    const email = req.body["email"];
    const password = req.body["password"];

    if (email === undefined || password === undefined)
        return res.status(400).json({"msg": "Bad parameter"});
    login(res, email, password, (success) => {
        if (!success)
            res.status(401).json({"msg": "Invalid Credentials"});
    });
});

export default router;
