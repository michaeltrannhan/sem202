#read input
library(readr)
diet = read_csv("Diet.csv")
View(diet)
#Clean NA
sum(is.na(diet))
diet <- na.omit(diet)
sum(is.na(diet))
View(diet)

#Features engineer
diet$weight.loss = diet$pre.weight - diet$weight6weeks
attach(diet)
diet$Diet = factor(diet$Diet, labels = c("A","B","C"))
diet$gender = factor(diet$gender, labels = c("Female","Male"))
View(diet)

#Plotting Boxplot
boxplot(weight.loss~Diet,data=diet,col="light gray",
        ylab = "Weight loss (kg)", xlab = "Diet type",na.rm = TRUE)
abline(h=0,col="blue")

#One way ANOVA
aov_1 <- aov(formula = weight.loss ~ Diet, data = diet)
print(aov_1)
summary(aov_1)

#using TukeyHSD to find the best diet 
TukeyHSD(aov_1)

#Levene Test for Homogeneity of Variances assumption
library(car)
leveneTest(weight.loss~Diet, data = diet)

#Res Histogram for Normality assumption
res <- aov_1$residuals
h<-hist(res, main="Histogram of standardised
residuals",xlab="Standardised residuals")
xfit <- seq(min(res), max(res), length = 40)
yfit <- dnorm(xfit, mean = mean(res), sd = sd(res))
yfit <- yfit * diff(h$mids[1:2]) * length(res) 
lines(xfit, yfit, col = "black", lwd = 2)
