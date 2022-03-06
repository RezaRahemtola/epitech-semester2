FROM debian:buster

WORKDIR /home/app

RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install nodejs npm -y
COPY ./app/* ./
RUN npm install
EXPOSE 3000
CMD [ "npm", "start" ]