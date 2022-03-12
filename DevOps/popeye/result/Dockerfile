FROM node:12-alpine

WORKDIR /home/app
COPY . .
RUN npm install
EXPOSE 80
CMD [ "node", "server.js" ]