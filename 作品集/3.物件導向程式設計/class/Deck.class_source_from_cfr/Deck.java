/*
 * Decompiled with CFR 0_118.
 * 
 * Could not load the following classes:
 *  Card
 *  Card$Suit
 */
import java.util.ArrayList;
import java.util.Random;

public class Deck {
    private ArrayList<Card> cards = new ArrayList();
    private ArrayList<Card> usedCard;
    private ArrayList<Card> openCard;
    public int nUsed;

    public Deck(int nDeck) {
        int i = 0;
        while (i < nDeck) {
            Card.Suit[] arrsuit = Card.Suit.values();
            int n = arrsuit.length;
            int n2 = 0;
            while (n2 < n) {
                Card.Suit s = arrsuit[n2];
                int v = 1;
                while (v <= 13) {
                    Card card = new Card(s, v);
                    this.cards.add(card);
                    ++v;
                }
                ++n2;
            }
            ++i;
        }
        this.usedCard = new ArrayList();
        this.openCard = new ArrayList();
        this.shuffle();
    }

    public void printDeck() {
        for (Card card : this.cards) {
            card.printCard();
        }
    }

    public ArrayList<Card> getAllCards() {
        return this.cards;
    }

    public void shuffle() {
        Random rnd = new Random();
        int i = this.cards.size() - 1;
        while (i >= 0) {
            int j = rnd.nextInt(i + 1);
            Card tmp = this.cards.get(j);
            this.cards.remove(j);
            this.cards.add(i, tmp);
            --i;
        }
        this.usedCard.clear();
        this.openCard.clear();
        this.nUsed = 0;
    }

    public Card getOneCard(boolean isOpened) {
        if (this.nUsed >= this.cards.size()) {
            this.shuffle();
        }
        Card card = this.cards.get(this.nUsed);
        ++this.nUsed;
        this.usedCard.add(card);
        if (isOpened) {
            this.openCard.add(card);
        }
        return card;
    }

    public ArrayList<Card> getOpenedCard() {
        return this.openCard;
    }

    public void finishOneRound() {
        this.openCard = (ArrayList)this.usedCard.clone();
    }
}
