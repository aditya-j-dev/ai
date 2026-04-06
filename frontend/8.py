import pandas as pd
import numpy as np

data1 = {
    'ID' : [101,102,103,104],
    'Name': ['Ankur', 'Aditya', 'Shubhrit', 'Dhairya'],
    'Age': [22, 20, np.nan, 29],
    'Score': [9000, np.nan, 7500, 8000]
}

data2 = {
    'ID' : [101,102,103,104],
    'Department' : ['IT', 'HR', 'Finance', 'Research']
}

frame1 = pd.DataFrame(data1)
frame2 = pd.DataFrame(data2)
print("Dataset: \n", frame1,'\n')
print(frame2)

# missing values
frame1['Age'] = frame1['Age'].fillna(frame1['Age'].mean()).round(0)
frame1['Score'] = frame1['Score'].fillna(frame1['Score'].mean()).round(0)
print("\nMissing Values filled: ")
print(frame1)

# Data Filtering
filtered = frame1[frame1['Score'] > 8100]
print("\nScores > 8100 :\n",filtered)

# Data Reshaping
reshaped = pd.melt(frame1, id_vars=['ID','Name'],
                   var_name='Attribute',
                   value_name='Value')

print("\nReshaped:\n", reshaped)

# Merge data
merged = pd.merge(frame1, frame2, on='ID', how='inner')
print("\nMerged:\n", merged)