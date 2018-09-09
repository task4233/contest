# coding : utf-8
import pandas as pd
import numpy as np


def load_dataset():
    location = 'dataset/'
    train_df = pd.read_csv(location + 'train.csv', dtype={'Age': np.float64}, )
    test_df = pd.read_csv(location + 'test.csv', dtype={'Age': np.float64}, )
    labels = train_df.Survived

    return train_df, test_df, labels


def main():
    train, test, labels = load_dataset()
    print(train.head())


if __name__ == "__main__":
    main()
