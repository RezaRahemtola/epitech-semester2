# First stage - Compilation
FROM maven:3.8.4-jdk-11-slim AS builder

WORKDIR /builder
COPY . .
RUN mvn dependency:resolve
RUN mvn package


# Second stage - Run
FROM openjdk:11-jre-slim

WORKDIR /worker
COPY --from=builder /builder/target .
CMD [ "java", "-jar", "worker-jar-with-dependencies.jar" ]
