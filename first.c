#include<stdio.h>

int main(){
  printf("hi");
}
  stages {
        stage('Checkout') {
            steps {
                git branch: 'master', url: 'https://github.com/Gokul79618/hostel.git'
            }
        }

        stage('Install Dependencies') {
            steps {
                // If your project files are inside a folder named 'hos', keep this
                // Otherwise, remove the dir('hos') wrapper
                dir('hos') {
                    bat '"C:\\Program Files\\nodejs\\npm.cmd" install'
                }
            }
        }

        stage('Build') {
            steps {
                dir('hos') {
                    bat '"C:\\Program Files\\nodejs\\npm.cmd" run build'
                }
            }
        }
    }

    post {
        success {
            echo "✅ React project built successfully!"
        }
        failure {
            echo "❌ Build failed!"
        }
    }
}
[28-10-2025 08:06 PM] Gokul Cse Nec: node_modules
build
.git
Dockerfile
.dockerignore
[28-10-2025 08:06 PM] Gokul Cse Nec: . dockerignore
[28-10-2025 08:06 PM] Gokul Cse Nec: FROM node:18-alpine AS build
# Set working directory inside container
WORKDIR /app
# Copy package.json and package-lock.json (if available)
COPY package*.json ./
# Install dependencies
RUN npm install
# Copy the rest of the app source code
COPY . .
RUN npm run build
# Stage 2: Serve the app using Nginx
FROM nginx:alpine
# Copy build output from previous stage to Nginx's HTML directory
COPY --from=build /app/dist /usr/share/nginx/html
# Expose port 80 inside the container
EXPOSE 80
# Start Nginx server
CMD ["nginx", "-g", "daemon off;"]
[28-10-2025 08:06 PM] Gokul Cse Nec: Dockerfile
[28-10-2025 08:08 PM] Gokul Cse Nec: docker pull node:18-alpine
docker pull nginx:alpine 
docker build -t hos .
docker run -d -p 3000:80 hos
[28-10-2025 08:10 PM] Gokul Cse Nec: docker pull node:18-alpine
docker pull nginx:alpine
docker build -t filename .
docker run -d -p 3000:80 filename
git init
git add .
git commit -m "hi"
git remote add origin 
git branch 
git branch -m main
git push -u origin main
