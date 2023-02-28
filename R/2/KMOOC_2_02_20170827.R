# data generation
set.seed(123456789)
N <- 20 # 샘플수 20개
X1 <- rnorm(N,1,2) # rormal distribution 평균 1 분산 2
X2 <- rnorm(N,0,1)
X3 <- rnorm(N,-1,1)
Y <- 3 + 2*X1 + 0*X2 + 5*X3 + rnorm(N,0,1)
# EDA - exploratory data analysis (탐색적 데이터 분석) 필요 산점도 보는게 제일 좋음

# exploratory data analysis
D <- data.frame(Y,X1,X2,X3) # 데이터프레임으로 연결함
pairs(D) #산점도 보여줌
cor(D) #상관계수를 알려줌

# estimation of coefficients
# true values: b0=3, b1=2, b2=0, b3=3

X <- as.matrix(cbind(rep(1,N),X1,X2,X3))# cbide(): 첫번째 칼럼이 N개행의 1이 있는 칼럼으로 설정
Bhat <- solve(t(X)%*%X)%*%t(X)%*%Y#bhat은 (X^T X)^(-1) %*%:행렬곱셈
Yhat <- X%*%Bhat
RSS <- sum((Y-Yhat)^2)
RSE <- sqrt(RSS/(N-3-1))
SE2 <- (RSE^2)*solve(t(X)%*%X)
se <- sqrt(SE2[row(SE2)==col(SE2)])#diagonal만 capture하려고 함
CI <- cbind(Bhat-1.96*se,Bhat+1.96*se)
T <- (Bhat-0)/se
P <- 2*(1-pt(abs(T),N-3-1))

# simple and convenient way
D <- data.frame(Y,X1,X2,X3)
f <- lm(Y~X1+X2+X3,data=D)
confint(f)
summary(f)

# model comparison
f1 <- lm(Y~X1+X2+X3,data=D)
f2 <- lm(Y~X1+X3,data=D)
summary(f1)
summary(f2)

# real data example: iris data set
D <- read.table('KMOOC_2_02_dataset_iris.txt',header=TRUE)
pairs(D)
f1 <- lm(Sepal.Length~Sepal.Width+Petal.Length+Petal.Width+Species,data=D)
f2 <- lm(Sepal.Length~Sepal.Width+Petal.Length+Species,data=D)
f3 <- lm(Sepal.Length~Sepal.Width+Petal.Width+Species,data=D)

