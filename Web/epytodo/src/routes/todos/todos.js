import { Router } from 'express';
import { auth } from '../../middleware/auth.js';
import { checkTodoId } from '../../middleware/notFound.js';
import { createTodo, updateTodo, deleteTodo, getAllTodos, getTodoById } from './todos.query.js';


const router = Router();

router.get("/", auth, (req, res) => {
    getAllTodos(res);
});

router.get("/:id", auth, checkTodoId, (req, res) => {
    const todoId = req.params.id;

    getTodoById(res, todoId);
});

router.post("/", auth, (req, res) => {
    const title = req.body["title"];
    const description = req.body["description"];
    const due_time = req.body["due_time"];
    const user_id = req.body["user_id"];
    const status = req.body["status"];

    if (title === undefined || description === undefined || due_time === undefined || user_id === undefined || status === undefined)
        return res.status(400).json({"msg":"Bad parameter"});
    createTodo(res, title, description, due_time, status, user_id);
});

router.put("/:id", auth, checkTodoId, (req, res) => {
    const todoId = req.params.id;
    const title = req.body["title"];
    const description = req.body["description"];
    const due_time = req.body["due_time"];
    const user_id = req.body["user_id"];
    const status = req.body["status"];

    if (title === undefined || description === undefined || due_time === undefined || user_id === undefined || status === undefined)
        return res.status(400).json({"msg":"Bad parameter"});
    updateTodo(res, todoId, title, description, due_time, status, user_id);
});

router.delete("/:id", auth, checkTodoId, (req, res) => {
    const todoId = req.params.id;

    deleteTodo(res, todoId);
});

export default router;
