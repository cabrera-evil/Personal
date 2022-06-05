netstat -ano | findstr LISTENING | findstr 8080
taskkill -PID 44756 -F