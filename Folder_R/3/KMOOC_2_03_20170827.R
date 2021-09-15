# read data
DATA <- read.table('KMOOC_2_03_dataset_salary.txt',header=TRUE)
dim(DATA)
data.train <- DATA[1:2000,]
data.test <- DATA[2001:3000,]

# loess
f.le <- loess(salary~age,data=data.train)
y.train.le <- predict(f.le,data.train)
y.test.le <- predict(f.le,data.test)
rmse.train.le <- sqrt(mean((y.train.le-data.train$salary)^2))
rmse.test.le <- sqrt(mean((y.test.le-data.test$salary)^2))

plot_fitted <- function(x,y,yhat) {
  plot(x,y)
  o <- order(x)
  lines(x[o],yhat[o],type='l',col=2,lwd=2)
}
plot_fitted(data.train$age,data.train$salary,y.train.le)

# polynomial regression
f.pl <- lm(salary~poly(age,5,raw=TRUE),data=data.train)
y.train.pl <- predict(f.pl,data.train)
y.test.pl <- predict(f.pl,data.test)
rmse.train.pl <- sqrt(mean((y.train.pl-data.train$salary)^2))
rmse.test.pl <- sqrt(mean((y.test.pl-data.test$salary)^2))
plot_fitted(data.train$age,data.train$salary,y.train.pl)

# spline
#install.packages('splines')
library(splines)

cutpt <- quantile(age,prob=seq(0,1,by=0.25))
cutpt <- cutpt[2:(length(cutpt)-1)]
f.sp <- lm(salary~bs(age,knots=cutpt),data=data.train)

y.train.sp <- predict(f.sp,data.train)
y.test.sp <- predict(f.sp,data.test)
rmse.train.sp <- sqrt(mean((y.train.sp-data.train$salary)^2))
rmse.test.sp <- sqrt(mean((y.test.sp-data.test$salary)^2))
plot_fitted(data.train$age,data.train$salary,y.train.sp)

# summary
rmse.mat = matrix(c(rmse.train.le,rmse.test.le,
                    rmse.train.pl,rmse.test.pl,
                    rmse.train.sp,rmse.test.sp),nrow=2)
colnames(rmse.mat) <- c('loess','poly','spline')
barplot(rmse.mat,beside=TRUE)



