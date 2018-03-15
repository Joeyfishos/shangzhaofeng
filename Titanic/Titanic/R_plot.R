suppressMessages(library('ggplot2'))
suppressMessages(library('ggthemes')) 
suppressMessages(library('scales')) 
suppressMessages(library('dplyr'))
suppressMessages(library('randomForest'))
suppressMessages(library('corrplot'))
suppressMessages(library('plyr'))
train<-read.csv("C:/Users/ZHAOFENG SHANG/Desktop/NoteBook/Kaggle_Titanic/train.csv")
test<-read.csv("C:/Users/ZHAOFENG SHANG/Desktop/NoteBook/Kaggle_Titanic/test.csv")

#reference :https://www.kaggle.com/vincentlugat/titanic-data-analysis-rf-prediction-0-81818
# http://yilinwei.com/project/Online-news-popularity-classification-with-R.html
full  <- bind_rows(train, test)

summary(full)

summary(train)

#1.Age vs survived
ggplot(train[1:891,], aes(Age, fill = factor(Survived))) +  # use survived to fill the graph
  geom_histogram(bins=30) + 
  xlab("Age")  + 
  ggtitle("Age vs Survived")+theme_bw()


#2.Sex vs survived
ggplot(train[1:891,],mapping=aes(Sex,fill=factor(Survived)))+geom_bar(stat='count')+ggtitle("Sex vs Survived")

tapply(train[1:891,]$Survived,train[1:891,]$Sex,mean)# apply the function mean into data train$survived,index is &Sex

help(tapply)
  
#3. Age VS Sex
ggplot(train[1:891,],mapping=aes(Age,fill=factor(Survived)))+geom_histogram(bins=30)+# for 
  ggtitle("Age vs Sex vs Survived")+
  xlab('Age')+ylab('count')+facet_grid(.~Sex)# horizonal to show the graph(Sex~. ->vertical) 
# the facet_grid for two variable, use . to change to single variable, variable~varibale

#4. Plcass vs Survived
ggplot(train[1:891,],aes(Pclass,fill=factor(Survived)))+geom_bar(stat='count')+# for categorical
  xlab('Pclass')+ylab('count')+ggtitle('Pclass vs sex vs survived')

#5. Pclass vs sex vs age vs survival 
# four variable, x,y to age,sex. fill to survived,facet_wrap to pclass
ggplot(train[1:891,], aes(x = Age, y = Sex)) + 
  geom_jitter(aes(colour = factor(Survived))) +   # scatter the point
  facet_wrap(~Pclass) + 
  labs(x = "Age", y = "Sex", title = "Pclass vs Sex vs Age vs Survived")

#6. Fare vs pclass

ggplot(train[1:891,],aes(x=Fare, y=Pclass))+geom_jitter(aes(colour=factor(Survived)))+
         theme(element_blank())+labs(x='Age',y='Pclass',title='Fare vs pclass')+
         scale_fill_discrete(name = "survived") 
  
         

train$Title <- gsub('(.*, )|(\\..*)', '', train$Name)

# Titles by Sex
table(train$Sex, train$Title)








