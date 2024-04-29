MARKET1 = True
MARKET2 = False
ITEM_COUNT = 5
market1Prices = [5, 7, 12, 3, 4]
market2Prices = [8, 4, 9, 9, 6]
markets = [None] * ITEM_COUNT

market1Point = 9
market2Point = 25

def buy_items():
    # initialize variables
    total_spent = 0
    market1_points = market1Point
    market2_points = market2Point

    # iterate over items and buy from the cheapest market with greedy algorithm
    for i in range(ITEM_COUNT):
        if market1_points >= market1Prices[i] and market2_points >= market2Prices[i]:
            if market1Prices[i] < market2Prices[i]:
                markets[i] = MARKET1
                total_spent += market1Prices[i]
                market1_points -= market1Prices[i]
            else:
                markets[i] = MARKET2
                total_spent += market2Prices[i]
                market2_points -= market2Prices[i]
        elif market1_points >= market1Prices[i]:
            markets[i] = MARKET1
            total_spent += market1Prices[i]
            market1_points -= market1Prices[i]
        elif market2_points >= market2Prices[i]:
            markets[i] = MARKET2
            total_spent += market2Prices[i]
            market2_points -= market2Prices[i]
        else:
            # buy from the cheaper market
            if market1Prices[i] < market2Prices[i]:
                markets[i] = MARKET1
                total_spent += market1Prices[i]
                market1_points -= market1Prices[i]
            else:
                markets[i] = MARKET2
                total_spent += market2Prices[i]
                market2_points -= market2Prices[i]

    return total_spent




# print market information
def print_markets():
    print("Market 1 Prices: ", market1Prices)
    print("Market 2 Prices: ", market2Prices)
    print("Market 1 Points: ", market1Point)
    print("Market 2 Points: ", market2Point)

    print("Total Money Spent: ", buy_items())
    for i, m in enumerate(markets):
        if m is None:
            print(f"Item {i+1}: Item not bought")
        else:
            print(f"Item {i+1}: {'Market 1' if m == MARKET1 else 'Market 2'}")




# main function
if __name__ == '__main__':
    print_markets()




