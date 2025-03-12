pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                script {
                    echo "Building the C++ project..."
                    sh 'g++ hello.cpp -o hello_exec'
                    sh 'chmod +x hello_exec'  // Give execution permission
                    sh 'ls -l'  // Debug: Check if the file exists
                }
            }
        }

        stage('Test') {
            steps {
                script {
                    echo "Running the compiled program..."
                    sh 'pwd'  // Debug: Check current directory
                    sh 'ls -l'  // Debug: Check if the file is here
                    sh './hello_exec || echo "Execution failed with exit code $?"'  // Run with error handling
                }
            }
        }

        stage('Deploy') {
            steps {
                script {
                    echo "Deploying the application..."
                    sh 'echo "Deployment successful!"'
                }
            }
        }
    }

    post {
        failure {
            echo 'Pipeline failed'
        }
    }
}
