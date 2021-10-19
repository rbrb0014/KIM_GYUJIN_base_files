# read data
DATA <- read.table('KMOOC_2_04_dataset_iris.txt',header=TRUE)
dim(DATA)
train.idx <- c(1:30,51:80)
data.train <- DATA[train.idx,]
data.test <- DATA[-train.idx,]

# simple logistic regression
f.slg <- glm(Species~Petal.Width,family=binomial(link='logit'),data=data.train)
y <- predict(f.slg,newdata=data.train,type='response')

plot(data.train$Petal.Width,data.train$Species=='virginica')
o <- order(data.train$Petal.Width)
lines(data.train$Petal.Width[o],y[o],col=2,lwd=2)

y <- predict(f.slg,newdata=data.train,type='response')
y.train.slg <- factor(y>0.5,levels=c(FALSE,TRUE),labels=c('versicolor','virginica'))
y <- predict(f.slg,newdata=data.test,type='response')
y.test.slg <-factor(y>0.5,levels=c(FALSE,TRUE),labels=c('versicolor','virginica'))

err.train.slg <- mean(y.train.slg!=data.train$Species)
err.test.slg <- mean(y.test.slg!=data.test$Species)

table(y.train.slg,data.train$Species)
table(y.test.slg,data.test$Species)

# logistic regression
f.lg <- glm(Species~.,family=binomial(link='logit'),data=data.train)

y <- predict(f.lg,newdata=data.train,type='response')
y.train.lg <- factor(y>0.5,levels=c(FALSE,TRUE),labels=c('versicolor','virginica'))
y <- predict(f.lg,newdata=data.test,type='response')
y.test.lg <-factor(y>0.5,levels=c(FALSE,TRUE),labels=c('versicolor','virginica'))

err.train.lg <- mean(y.train.lg!=data.train$Species)
err.test.lg <- mean(y.test.lg!=data.test$Species)

table(y.train.lg,data.train$Species)
table(y.test.lg,data.test$Species)

# lda
library(MASS)

f.lda <- lda(Species~.,data=data.train)

y.train.lda <- predict(f.lda,data.train)
y.test.lda <- predict(f.lda,data.test)

err.train.lda <- mean(y.train.lda$class!=data.train$Species)
err.test.lda <- mean(y.test.lda$class!=data.test$Species)

table(y.train.lda$class,data.train$Species)
table(y.test.lda$class,data.test$Species)

# svm
#install.packages("e1071")
library(e1071)

f.svm <- svm(Species~.,data=data.train)

y.train.svm <- predict(f.svm,data.train)
y.test.svm <- predict(f.svm,data.test)

err.train.svm <- mean(y.train.svm!=data.train$Species)
err.test.svm <- mean(y.test.svm!=data.test$Species)

table(y.train.svm,data.train$Species)
table(y.test.svm,data.test$Species)

# summary
ERR <- matrix(c(err.train.slg,err.test.slg,
                err.train.lg,err.test.lg,
                err.train.lda,err.test.lda,
                err.train.svm,err.test.svm),nrow=2)
colnames(ERR) <- c('SLG','LG','LDA','SVM')
row.names(ERR) <- c('train','test')
barplot(ERR,beside=TRUE)




