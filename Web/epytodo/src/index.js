import express from 'express';
import 'dotenv/config';
import auth from './routes/auth/auth.js';
import user from './routes/user/user.js';
import todos from './routes/todos/todos.js';


const app = express();
const port = process.env.PORT;

// Express middlewares instead of bodyparser
app.use(express.urlencoded({extended: true}));
app.use(express.json());
app.use(express.raw());

app.use("/", auth);
app.use("/", user);
app.use("/todos", todos);

app.listen(port, (error) => {
    if (error)
        return console.log(`error: ${error}`);
    console.log(`EpyTodo listening at http://localhost:${port}`);
});
