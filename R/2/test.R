set.seed(123456789)
N <- 20 # 샘플수 20개
X1 <- rnorm(N,1,2) # rormal distribution 평균 1 분산 2
X1
X2 <- rnorm(N,0,1)
X3 <- rnorm(N,-1,1)
Y <- 3+2*X1+0*X2+5*X3+rnorm(N,0,1)
# EDA - exploratory data analysis (탐색적 데이터 분석) 필요 산점도 보는게 제일 좋음
D <- data.frame(Y,X1,X2,X3) # 데이터프레임으로 연결함
D[1:10,]
pairs(D) #산점도 보여줌
cor(D) #상관계수를 알려줌
X <- as.matrix(cbind(rep(1,N),X1,X2,X3)) # cbide(): 첫번째 칼럼이 N개행의 1이 있는 칼럼으로 설정
X[1:10,]
dim(X) # X의 차원: 20행 4열
Bhat <- solve(t(X)%*%X) %*% t(X) %*% Y #bhat은 (X^T X)^(-1) %*%:행렬곱셈
Bhat
Yhat <- X%*%Bhat
RSS <- sum((Y-Yhat)^2)
RSE <- sqrt(RSS/(N-3-1))
SE2 <- (RSE^2)*solve(t(X)%*%X)
SE2
row(SE2)
col(SE2)
SE2[row(SE2)==col(SE2)] #diagonal만 capture하려고 함
se <- sqrt(SE2[row(SE2)==col(SE2)])
se
Bhat
CI <- cbind(Bhat-1.96*se,Bhat+1.96*se)
CI # 신뢰구간을 보여줌
T <- (Bhat-0)/se
T
T[0]
T[1,1]
pt(T[1,1],N-3-1)#cdf값임
1-pt(T[1,1],N-3-1)
2*(1-pt(T[1,1],N-3-1)) #p값임
P <- 2*(1-pt(T,N-3-1))
P #X2가 보면 0.75임 개큼. 5% 초과니까 상ㅇ관 없을 확률 높음
Bhat
CI
P
D <- data.frame(Y,X1,X2,X3)
f <- lm(Y~X1+X2+X3,data=D)#linear model을 만드는데, Y~X1,X2,X3고 data test 값은 D이다.
f <- lm(Y~.,data=D)#D에있는 변수(Y,X1,X2,X3중 나머지에 대해 전부에 대해 만들어줘라)
#******이 모델만드는 함수가 거의 전부이다. 이걸 기억해라.******
f
summary(f)
RSE
P
confint(f)#신뢰구간 (기본 95%)
CI#값 조금 다른 이유:CI는 normal dist.에서 오기 때문
