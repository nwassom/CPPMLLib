import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression

# Read data from input file
data = pd.read_csv('../data.csv', header=None)

# Reshape and get data
X = data.iloc[:,0].values.reshape(-1, 1)
y = data.iloc[:,1].values

# Create model and train it with the data
model = LinearRegression()
model.fit(X, y)

# Give input and predict
# user_input = np.array([[float(input("Enter X Value for prediction: "))]])

user_input = np.array([[float(72.5)]])

predicted_y = model.predict(user_input)

print(f"Predicted y for X values of {user_input[0]} is {predicted_y[0]}")

