/* Momos Market
Send Feedback
Shreya loves to eat momos. Her mother gives her money to buy vegetables but she manages to save some money out of it daily. After buying vegetables, she goes to "Momos Market", where there are ‘n’ number of shops of momos. Each of the shops of momos has a rate per momo. She visits the market and starts buying momos (one from each shop) starting from the first shop. She will visit the market for ‘q’ days. You have to tell that how many momos she can buy each day if she starts buying from the first shop daily. She cannot use the remaining money of one day on some other day. But she will save them for other expenses in the future, so, you also need to tell the sum of money left with her at the end of each day.
Input Format:
First line will have an integer ‘n’ denoting the number of shops in market.
Next line will have ‘n’ numbers denoting the price of one momo of each shop.
Next line will have an integer ‘q’ denoting the number of days she will visit the market.
Next ‘q’ lines will have one integer ‘X’ denoting the money she saved after buying vegetables.
Constraints:
1 <= n <= 10^5
1 <= q <= 10^5
1 <= X <= 10^9
Output:
There will be ‘q’ lines of output each having two space separated integers denoting number of momos she can buy and amount of money she saved each day.
Sample Input:
4
2 1 6 3
1
11
Sample Output:
3 2
Explanation:
Shreya visits the "Momos Market" for only one day. She has 11 INR to spend. She can buy 3 momos, each from the first 3 shops. She would 9 INR (2 + 1 + 6) for the same and hence, she will save 2 INR. */

#include <bits/stdc++.h>
using namespace std;

void getIndexBinary( int *prefixSum, int numberOfShops, int todaysmoney)
{
    int index = 0;
    // int todaysmoney = money[i];

    // check if this money is less than required at first shop
    if (todaysmoney<prefixSum[0])
    {
        cout<<0<< " "<<todaysmoney<<endl;
        return;
    }
    if (todaysmoney == prefixSum[0])
    {
        cout << 1 << " " << todaysmoney-prefixSum[0] << endl;
        return;
    }
    if (todaysmoney >= prefixSum[numberOfShops-1])
    {
        cout << numberOfShops << " " << todaysmoney - prefixSum[numberOfShops - 1] << endl;
        return;
    }
    // check if this money is greater than all sums ie. last index


    int start = 0, end = numberOfShops - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (prefixSum[mid] == todaysmoney)
        {
            index = mid;
            break;
        }
        else if (prefixSum[mid] < todaysmoney)
        {
            if (todaysmoney < prefixSum[mid + 1])
            {
                index = mid;
                break;
            }
            start = mid + 1;
        }
        else if (prefixSum[mid] > todaysmoney)
        {
            if (todaysmoney > prefixSum[mid - 1])
            {
                index = mid - 1;
                break;
            }
            end = mid - 1;
        }
    }

    cout << index + 1 << " " << todaysmoney - prefixSum[index] << endl;
}

int main()
{
    int numberOfShops, numberOfDays, x;
    cin >> numberOfShops;
    int momosCost[numberOfShops];
    for (int i = 0; i < numberOfShops; i++)
    {
        cin >> momosCost[i];
    }
    cin >> numberOfDays;
    int money[numberOfDays];
    for (int i = 0; i < numberOfDays; i++)
    {
        cin >> money[i];
    }
    int prefixSum[numberOfShops];
    // find continuous sum (prefix sum) - eg array 2,1,3,4 -> cont sum => 2 ,3 ,6 ,10
    prefixSum[0] = momosCost[0];
    // Adding present element with previous element
    for (int i = 1; i < numberOfShops; i++)
        prefixSum[i] = prefixSum[i - 1] + momosCost[i];

    // for every saved money find its posn in price continuous sum using binary search
    for (int i = 0; i < numberOfDays; i++)
    {
        getIndexBinary( prefixSum,  numberOfShops,  money[i]);
    }

    //* Base aproch O(n2)
    // for (long long i = 0; i < days; i++){
    //     long long remain = 0, momo = 0, money = saved_money[i];
    //     for (long long j = 0; j < n; j++)
    //     {
    //         if(money - shops[j] >= 0){
    //             momo++;
    //             money -= shops[j];
    //             remain = money;
    //         } else {

    //             break;
    //         }
    //     }
    //     cout << momo << " " << remain << endl;
    // }


    return 0;
}