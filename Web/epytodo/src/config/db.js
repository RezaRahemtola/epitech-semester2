import { createConnection } from 'mysql2';


const connection = createConnection({
    host: process.env.MYSQL_HOST,
    user: process.env.MYSQL_USER,
    password: process.env.MYSQL_ROOT_PASSWORD,
    database: process.env.MYSQL_DATABASE
});

connection.connect((error) => {
    if (error)
        console.error(`Database connection error: ${error.message}`);
});

export default connection;
