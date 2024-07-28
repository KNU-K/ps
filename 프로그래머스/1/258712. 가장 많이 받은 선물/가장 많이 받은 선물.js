const makeMapAndGiftCount = (friends) => {
    let map = {};
    let map2 = {};
    for (friend1 of friends) {
        map[friend1] = {};
        map2[friend1] = 0;
        for (friend2 of friends) {
            if (friend1 === friend2) continue;
            map[friend1][friend2] = {};
            map[friend1][friend2]["준거"] = 0;
            map[friend1][friend2]["받은거"] = 0;
        }
    }
    return [map, map2];
};
const calcGift = (friendMaps, gifts) => {
    friendMaps[gifts[0]][gifts[1]]["준거"]++;
    friendMaps[gifts[1]][gifts[0]]["받은거"]++;
};
function solution(friends, gifts) {
    var answer = 0;
    const [friendMaps, giftCounts] = makeMapAndGiftCount(friends);
    for (gift of gifts) {
        calcGift(friendMaps, gift.split(" "));
    }

    const GiftIndexMap = {};
    let visit = {};

    for (friend1 of friends) {
        visit[friend1] = 0;
        GiftIndexMap[friend1] = {};
        GiftIndexMap[friend1]["준거"] = 0;
        GiftIndexMap[friend1]["받은거"] = 0;
        GiftIndexMap[friend1]["선물지수"] = 0;
    }
    for (friend1 of friends) {
        for (friend2 of friends) {
            if (friend1 === friend2) continue;
            const cnt = friendMaps[friend1][friend2]["준거"];
            GiftIndexMap[friend1]["준거"] += cnt;
            GiftIndexMap[friend2]["받은거"] += cnt;
        }
    }
    for (friend2 of friends) {
        GiftIndexMap[friend2]["선물지수"] = GiftIndexMap[friend2]["준거"] - GiftIndexMap[friend2]["받은거"];
    }

    for (friend1 of friends) {
        visit[friend1] = 1;
        for (friend2 of friends) {
            if (visit[friend2] === 0) continue;
            if (friend1 === friend2) continue;
            if (friendMaps[friend1][friend2]["준거"] != 0 || friendMaps[friend1][friend2]["받은거"] != 0) {
                if (friendMaps[friend1][friend2]["준거"] > friendMaps[friend1][friend2]["받은거"]) {
                    giftCounts[friend1]++;
                } else if (friendMaps[friend1][friend2]["준거"] < friendMaps[friend1][friend2]["받은거"]) {
                    giftCounts[friend2]++;
                } else {
                    if (GiftIndexMap[friend1]["선물지수"] > GiftIndexMap[friend2]["선물지수"]) {
                        giftCounts[friend1]++;
                    } else if (GiftIndexMap[friend1]["선물지수"] < GiftIndexMap[friend2]["선물지수"]) {
                        giftCounts[friend2]++;
                    }
                }
            } else {
                if (GiftIndexMap[friend1]["선물지수"] > GiftIndexMap[friend2]["선물지수"]) {
                    giftCounts[friend1]++;
                } else if (GiftIndexMap[friend1]["선물지수"] < GiftIndexMap[friend2]["선물지수"]) {
                    giftCounts[friend2]++;
                }
            }
        }
    }
    let max = 0;
    for (friend1 of friends) {
        if (max < giftCounts[friend1]) max = giftCounts[friend1];
    }
    return max;
}