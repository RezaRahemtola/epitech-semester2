import jwt from 'jsonwebtoken';


export const auth = (req, res, next) => {
    const authorization = req.headers.authorization;

    if (authorization) {
        // Authorization header format is [key, token, string]
        const token = authorization.split(' ')[1];

        jwt.verify(token, process.env.SECRET, (error, decodedUserId) => {
            if (error) {
                res.status(498).json({"msg": "Token is not valid"});
            } else {
                // Set user id to access it later
                req.userId = decodedUserId;
                next();
            }
        });
    } else {
        res.status(498).json({"msg": "No token, authorization denied"});
    }
};
