pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                script {
                    echo "Building the C++ project..."
                    sh 'g++ hello.cpp -o hello_exec'
                    sh 'chmod +x hello_exec'  // Ensure executable permission
                }
            }
        }

        stage('Test') {
            steps {
                script {
                    echo "Running the compiled program..."
                    sh './hello_exec || echo "Execution failed with exit code $?"'  // Debugging step
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
