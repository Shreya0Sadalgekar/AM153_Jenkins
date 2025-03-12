pipeline {
    agent any
    
    stages {
        stage('Build') {
            steps {
                build 'AM153-cpp'
                script {
                    echo "Building the C++ project..."
                    sh 'g++ hello.cpp -o output'
                }
            }
        }

        stage('Test') {
            steps {
                sh './output'
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
            error 'Pipeline failed'
        }
    }
}
