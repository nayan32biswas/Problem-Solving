logf = open("grad.txt", "r")
Xi = [float(x) for x in logf.readline().split(" ")]
Yi = [float(x) for x in logf.readline().split(" ")]

m = 10
i = 0
totalIterations = 500
Theta1 = 2.5
Theta0 = -15
Cost = 522.822
Alpha = 0.001

while(i <= totalIterations):
    print(f"Iteration: {i}\tTheta 1: {Theta1} \tTheta 0 : {Theta0}\t\tCost Value : {Cost}")
    i += 1
    Dell0 = 0
    Dell1 = 0
    for j in range(m):
        Dell0 = Dell0 + (Theta1*Xi[j]+Theta0-Yi[j])
        Dell1 = Dell1 + ((Theta1*Xi[j]+Theta0-Yi[j])*Xi[j])
    Dell0 = (1/m)*Dell0
    Dell1 = (1/m)*Dell1

    Theta0 = Theta0 - Alpha*Dell0
    Theta1 = Theta1 - Alpha*Dell1

    Cost = 0
    for j in range(m):
        Cost = Cost + (Theta1*Xi[j]+Theta0-Yi[j])**2
    Cost = Cost/(2*m)
