class Solution
{
public:
    int cnt = 0;
    void permute(string tiles, int ind)
    {
        for (int i = ind; i < tiles.size(); i++)
        {
            if (i != ind && tiles[i] == tiles[ind])
                continue;
            swap(tiles[i], tiles[ind]);
            cnt++;
            permute(tiles, ind + 1);
        }
    }

    int numTilePossibilities(string tiles)
    {
        sort(tiles.begin(), tiles.end());
        permute(tiles, 0);
        return cnt;
    }
};