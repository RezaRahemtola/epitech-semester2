# First stage - Compilation
FROM maven:3.5-jdk-8-alpine AS builder

WORKDIR /builder
COPY . .
RUN mvn dependency:resolve
RUN mvn package


# Second stage - Run
FROM openjdk:8-jre-alpine

WORKDIR /worker
COPY --from=builder /builder/target .
CMD [ "java", "-jar", "worker-jar-with-dependencies.jar" ]