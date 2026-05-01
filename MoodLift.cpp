#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <random>
using namespace std;

// DATA STRUCTURES

struct MoodPackage {
    string verse;
    string quote;
    string message;
};

struct HistoryEntry {
    string date;
    string mood;
    string note;
};

// MOOD CONTENT 

map<string, vector<MoodPackage>> mood_content = {
    {"Sad/Downcast", {
        {"Psalm 34:18 - \"The Lord is close to the brokenhearted and saves those who are crushed in spirit.\"",
         "\"It's so difficult to describe depression to someone who's never been there because it's not sadness.\" - J.K. Rowling",
         "You're feeling really heavy and down right now, and that's completely valid. It's okay to let the tears come. Take a gentle 5-minute pause to wrap yourself in a blanket or hold something soft and comforting."},
        {"Psalm 42:11 - \"Why, my soul, are you downcast? Why so disturbed within me? Put your hope in God, for I will yet praise him, my Savior and my God.\"",
         "\"Depression is your body saying, 'I don't want to be this character anymore.'\" - Jim Carrey",
         "This sadness is weighing on you deeply. Give yourself permission to feel it without judgment. Try stepping outside for fresh air or just sitting by a window for a few minutes to let light in."},
        {"Psalm 30:5 - \"Weeping may stay for the night, but rejoicing comes in the morning.\"",
         "\"I found that, with depression, one of the most important things you could realize is that you're not alone.\" - Dwayne Johnson",
         "Your heart feels low, and it's exhausting carrying that. It's okay to rest. Put on a soothing song or nature sounds and close your eyes for 10 minutes - no pressure to feel better yet."},
        {"Deuteronomy 31:8 - \"The Lord himself goes before you and will be with you; he will never leave you nor forsake you. Do not be afraid; do not be discouraged.\"",
         "\"Depression doesn't take away your talents - it just makes them harder to find.\" - Lady Gaga",
         "You're hurting inside, and that's real. Be kind to yourself like you would a friend. Grab a warm drink, sip slowly, and focus on the warmth in your hands."},
        {"Psalm 9:9 - \"The Lord is a refuge for the oppressed, a stronghold in times of trouble.\"",
         "\"Behind every sweet smile, there is a bitter sadness that no one can ever see and feel.\" - Tupac Shakur",
         "Sadness can make everything feel dim. You're allowed to slow down. Try naming three small things you can still notice (a soft texture, a familiar scent) to ground yourself gently."},
        {"Isaiah 41:10 - \"So do not fear, for I am with you; do not be dismayed, for I am your God. I will strengthen you and help you; I will uphold you with my righteous right hand.\"",
         "\"Depression is melancholy minus its charms.\" - Susan Sontag",
         "This downcast feeling is tough, and you're not failing for having it. Pause here: place a hand on your chest, breathe slowly, and whisper something kind to yourself."},
        {"Psalm 3:3 - \"But you, Lord, are a shield around me, my glory, the One who lifts my head high.\"",
         "\"Sadness is...I know sadness is not a bad thing. To cry and to feel. But it's that cold absence of feeling - that really hollowed-out feeling.\" - J.K. Rowling",
         "You're carrying quiet grief or emptiness right now. It's okay to not push through. Curl up with a favorite photo, memory, or object for a short moment of tenderness."},
        {"2 Corinthians 7:6 - \"But God, who comforts the downcast, comforted us...\"",
         "\"For me, depression is not sadness. It's not having a bad day and needing a hug.\" - Kristen Bell",
         "Feeling blue can drain you completely. Give yourself grace. Take a slow stretch or gentle rock side to side to release a bit of tension in your body."},
        {"Psalm 147:3 - \"He heals the brokenhearted and binds up their wounds.\"",
         "\"That's the thing about depression: A human being can survive almost anything, as long as she sees the end in sight.\" - Elizabeth Wurtzel",
         "Your spirit feels low, and that's okay today. Rest in this: light a candle or turn on soft light, and just sit with it for 5 minutes without forcing a change."},
        {"Matthew 5:4 - \"Blessed are those who mourn, for they will be comforted.\"",
         "\"Depression is feeling like you've lost something but having no clue when or where you last had it.\" - Anonymous",
         "Sadness is visiting, and it's heavy. You're allowed space. Try writing one honest sentence about how you feel, then close the notebook - no need to fix it."}
    }},
    {"Anxious/Worried", {
        {"Philippians 4:6-7 - \"Do not be anxious about anything, but in every situation, by prayer and petition, with thanksgiving, present your requests to God.\"",
         "\"Worrying is carrying tomorrow's load with today's strength - carrying two days at once.\" - Corrie ten Boom",
         "Your mind is racing with worries right now, and that's exhausting. It's okay to interrupt the spiral. Take a slow 4-7-8 breath: inhale 4, hold 7, exhale 8."},
        {"1 Peter 5:7 - \"Cast all your anxiety on him because he cares for you.\"",
         "\"Anxiety is the dizziness of freedom.\" - Soren Kierkegaard",
         "Anxiety is buzzing loudly inside you. Give yourself permission to step back. Name 5 things you can see around you to anchor in the present."},
        {"Matthew 6:34 - \"Therefore do not worry about tomorrow, for tomorrow will worry about itself...\"",
         "\"Our anxiety does not empty tomorrow of its sorrows, but only empties today of its strengths.\" - C.H. Spurgeon",
         "You're feeling on edge with \"what ifs.\" That's real. Pause: place one hand on your belly, feel it rise and fall with 5 slow breaths."},
        {"Isaiah 41:10 - \"So do not fear, for I am with you...\"",
         "\"I've had a lot of worries in my life, most of which never happened.\" - Mark Twain",
         "Worry is looping and tight. It's okay to pause the thoughts. Chew gum slowly or sip cold water mindfully to shift focus."},
        {"Proverbs 3:5-6 - \"Trust in the Lord with all your heart and lean not on your own understanding...\"",
         "\"The only thing we have to fear is fear itself.\" - Franklin D. Roosevelt",
         "Your heart is pounding from anxiety. You're safe right now. Try gentle stretches - reach arms up, then down - to release tension."},
        {"Psalm 55:22 - \"Cast your cares on the Lord and he will sustain you...\"",
         "\"Anxiety is a thin stream of fear trickling through the mind. If encouraged, it cuts a channel into which all other thoughts are drained.\" - Arthur Somers Roche",
         "Worries feel overwhelming and endless. Slow it down: count backward from 20 slowly while breathing deeply."},
        {"John 14:27 - \"Peace I leave with you; my peace I give you...\"",
         "\"Do not anticipate trouble, or worry about what may never happen. Keep in the sunlight.\" - Benjamin Franklin",
         "Anxiety is making everything feel urgent. It's okay to say \"not now.\" Close your eyes for 1 minute and listen to sounds around you."},
        {"Matthew 11:28-30 - \"Come to me, all you who are weary and burdened, and I will give you rest.\"",
         "\"Unease, anxiety, tension, stress, worry - all forms of fear - are caused by too much future, and not enough presence.\" - Eckhart Tolle",
         "Your thoughts are spinning fast. Ground yourself: touch something solid nearby and describe its texture out loud."},
        {"Isaiah 26:3 - \"You will keep in perfect peace those whose minds are steadfast, because they trust in you.\"",
         "\"Anxiety's like a rocking chair. It gives you something to do, but it doesn't get you very far.\" - Jodi Picoult",
         "Worry is gripping tight today. Release a bit: shake out your hands and arms like shaking off water for 30 seconds."},
        {"Psalm 56:3 - \"When I am afraid, I put my trust in you.\"",
         "\"Worry often gives a small thing a big shadow.\" - Swedish proverb",
         "Anxiety feels like it's everywhere. Narrow it: focus only on your next breath, then the one after."}
    }},
    {"Unmotivated/Low Energy", {
        {"Isaiah 40:31 - \"But those who hope in the Lord will renew their strength. They will soar on wings like eagles...\"",
         "\"The man who moves a mountain begins by carrying away small stones.\" - Confucius",
         "You're feeling zero motivation and low on energy right now, and that's draining. It's okay to start tiny. Commit to just 2 minutes of one small thing - like standing up and stretching."},
        {"Philippians 4:13 - \"I can do all this through him who gives me strength.\"",
         "\"Our deepest fear is not that we are inadequate. Our deepest fear is that we are powerful beyond measure.\" - Marianne Williamson",
         "Low energy is making everything feel impossible. Give yourself grace. Set a timer for 5 minutes and do the easiest first step - no more."},
        {"2 Corinthians 12:9 - \"My grace is sufficient for you, for my power is made perfect in weakness.\"",
         "\"Success is stumbling from failure to failure with no loss of enthusiasm.\" - Winston Churchill",
         "Motivation is nowhere today, and your body feels heavy. That's fine. Try one micro-action: make your bed or open a window for fresh air."},
        {"Joshua 1:9 - \"Be strong and courageous... for the Lord your God will be with you...\"",
         "\"Many of life's failures are people who did not realize how close they were to success when they gave up.\" - Thomas Edison",
         "You're unmotivated and wiped out. It's okay not to force big things. Pick the smallest win: drink a full glass of water slowly."},
        {"Psalm 73:26 - \"My flesh and my heart may fail, but God is the strength of my heart...\"",
         "\"Believe you can and you're halfway there.\" - Theodore Roosevelt",
         "Low drive has you stuck. Be kind. Stand and do 10 gentle marches in place to wake your body a bit."},
        {"Galatians 6:9 - \"Let us not become weary in doing good, for at the proper time we will reap a harvest if we do not give up.\"",
         "\"Run when you can, walk if you have to, crawl if you must; just never give up.\" - Dean Karnazes",
         "Energy is flat, motivation gone. Allow rest first. After a 10-minute lie-down, try one easy task like sorting one item."},
        {"Jeremiah 29:11 - \"For I know the plans I have for you... plans to give you hope and a future.\"",
         "\"You've got to get up every morning with determination if you're going to go to bed with satisfaction.\" - George Horace Lorimer",
         "Feeling blah and unmotivated is real. Start where you are: change position (sit to stand) and notice how it shifts slightly."},
        {"Ephesians 3:16 - \"I pray that out of his glorious riches he may strengthen you with power through his Spirit...\"",
         "\"Keep your face toward the sunshine - and shadows will fall behind you.\" - Walt Whitman",
         "No spark today, just low battery. That's temporary. Do a 2-minute \"activation\": wiggle toes, fingers, then shoulders."},
        {"Hebrews 12:1-2 - \"Let us run with perseverance the race marked out for us, fixing our eyes on Jesus...\"",
         "\"We are what we repeatedly do. Excellence, therefore, is not an act but a habit.\" - Aristotle",
         "Motivation feels missing entirely. It's okay. Reward the tiniest effort: put on a favorite song and sway for 60 seconds."},
        {"Nehemiah 8:10 - \"The joy of the Lord is your strength.\"",
         "\"Most of the important things in the world have been accomplished by people who have kept on trying when there seemed to be no hope at all.\" - Dale Carnegie",
         "Low energy makes starting hard. Shrink the start: tell yourself \"just open the app/notebook\" and see what happens."}
    }},
    {"Grateful/Content", {
        {"1 Thessalonians 5:18 - \"Give thanks in all circumstances; for this is God's will for you in Christ Jesus.\"",
         "\"Gratitude is not only the greatest of virtues but the parent of all others.\" - Marcus Tullius Cicero",
         "You're in a peaceful, content place right now, and that's wonderful. Savor it. Take a slow 2-minute pause to notice three things you're thankful for in this exact moment."},
        {"Philippians 4:11-12 - \"I have learned to be content whatever the circumstances...\"",
         "\"Let us be grateful to the people who make us happy; they are the charming gardeners who make our souls blossom.\" - Marcel Proust",
         "Gratitude is filling you gently today. Lean in. Write or say aloud one specific thing you appreciate about your surroundings right now."},
        {"Psalm 100:4 - \"Enter his gates with thanksgiving and his courts with praise...\"",
         "\"When you are grateful, fear disappears and abundance appears.\" - Tony Robbins",
         "Contentment feels calm and full. Protect it. Spend 5 minutes breathing deeply while thinking of one person or moment that brings warmth."},
        {"Colossians 3:15 - \"Let the peace of Christ rule in your hearts... And be thankful.\"",
         "\"Gratitude turns what we have into enough.\" - Aesop",
         "You're feeling quietly grateful. Amplify it. Touch something you love (soft blanket, favorite mug) and thank it silently."},
        {"Psalm 107:1 - \"Give thanks to the Lord, for he is good; his love endures forever.\"",
         "\"I am grateful for what I am and have. My thanksgiving is perpetual.\" - Henry David Thoreau",
         "This contentment is a soft gift. Receive it. Look around and mentally list small comforts - like light, air, quiet."},
        {"1 Chronicles 16:34 - \"Give thanks to the Lord, for he is good; his love endures forever.\"",
         "\"Even if you don't have all the things you want, be grateful for the things you don't have that you don't want.\" - Bob Dylan",
         "Gratitude is present and steady. Nurture it. Send a quick thankful thought or text to someone who matters."},
        {"Ephesians 5:20 - \"Always giving thanks to God the Father for everything...\"",
         "\"Gratitude is a powerful catalyst for happiness. It's the spark that lights a fire of joy in your soul.\" - Amy Collette",
         "You're content in the now. Anchor there. Close your eyes, breathe, and feel the peace in your body."},
        {"Psalm 103:2 - \"Praise the Lord, my soul, and forget not all his benefits.\"",
         "\"Gratitude makes sense of our past, brings peace for today, and creates a vision for tomorrow.\" - Melody Beattie",
         "Thankful heart is open today. Share lightly: notice one beauty outside or in your space and hold the appreciation."},
        {"James 1:17 - \"Every good and perfect gift is from above...\"",
         "\"Be grateful for what you already have while you pursue your goals.\" - Roy T. Bennett",
         "Contentment wraps around you nicely. Enjoy without rush. Sip something warm and focus fully on the taste."},
        {"Colossians 2:6-7 - \"Overflowing with thankfulness.\"",
         "\"Great things happen to those who don't stop believing, trying, learning, and being grateful.\" - Roy T. Bennett",
         "Gratitude flows easily right now. Capture it: take a mental snapshot of this feeling to recall later."}
    }},
    {"Stressed/Overwhelmed", {
        {"Matthew 11:28-30 - \"Come to me, all you who are weary and burdened, and I will give you rest.\"",
         "\"For fast-acting relief, try slowing down.\" - Lily Tomlin",
         "You're carrying a lot right now, and it's overwhelming. It's okay to pause. Take a 10-minute break to do something that calms you - walk, stretch, or simply breathe."},
        {"Psalm 55:22 - \"Cast your cares on the Lord and he will sustain you...\"",
         "\"Much of the stress that people feel doesn't come from having too much to do. It comes from not finishing what they've started.\" - David Allen",
         "Everything feels like too much at once, and that's exhausting. Give yourself permission to stop. Step away for 5 minutes and do box breathing: in 4, hold 4, out 4, hold 4."},
        {"1 Peter 5:7 - \"Cast all your anxiety on him because he cares for you.\"",
         "\"Stress is simply the adaptation of our bodies and minds to change.\" - Peter G. Hanson",
         "The load is heavy today, and your body knows it. It's valid. Put your tasks on hold briefly - sip water slowly or look out a window."},
        {"Isaiah 41:10 - \"So do not fear... I will strengthen you and help you...\"",
         "\"Sometimes the most productive thing you can do is relax.\" - Various",
         "Stress is piling up fast. You're allowed a timeout. Tense your shoulders up, then drop them while exhaling long."},
        {"Philippians 4:6-7 - \"Do not be anxious about anything...\"",
         "\"Almost everything will work again if you unplug it for a few minutes... including you.\" - Anne Lamott",
         "Overwhelm has you spinning. Slow the spin: name three things you can touch right now to come back to here."},
        {"Psalm 46:1-3 - \"God is our refuge and strength, an ever-present help in trouble.\"",
         "\"Reality is the leading cause of stress for those in touch with it.\" - Jane Wagner",
         "You're juggling more than feels possible. Drop gently: close your eyes for 2 minutes and focus only on your breath."},
        {"Isaiah 40:31 - \"But those who hope in the Lord will renew their strength...\"",
         "\"You cannot always control what goes on outside. But you can always control what goes on inside.\" - Wayne Dyer",
         "Everything screaming for attention. It's okay to mute some. Pick one small thing to do, then reward with a deep sigh."},
        {"Psalm 61:2 - \"Lead me to the rock that is higher than I.\"",
         "\"Stop a minute, right where you are. Relax your shoulders, shake your head and spine like a dog shaking off cold water.\" - Various",
         "The pressure feels crushing. Lighten your grip: shake out your hands vigorously for 20 seconds."},
        {"Exodus 14:14 - \"The Lord will fight for you; you need only to be still.\"",
         "\"There are some things you learn best in calm, and some in storm.\" - Willa Cather",
         "Stressed and scattered right now. Gather: rub palms together to warm them, cup over eyes for calm darkness."},
        {"Psalm 23:4 - \"Even though I walk through the darkest valley...\"",
         "\"Stress acts as an accelerator: it will push you either forward or backward, but you choose which direction.\" - Various",
         "Overwhelm is loud in your mind. Quiet it: hum a low note or sigh audibly to release tension."}
    }},
    {"Lonely/Isolated", {
        {"Deuteronomy 31:6 - \"He will never leave you nor forsake you.\"",
         "\"Loneliness expresses the pain of being alone, and solitude expresses the glory of being alone.\" - Paul Tillich",
         "You're feeling really alone right now, and that ache is real. It's okay to reach out gently. Text or call one person just to say hi or share how you're feeling."},
        {"Isaiah 41:10 - \"For I am with you...\"",
         "\"Loneliness is the poverty of self; solitude is richness of self.\" - May Sarton",
         "Loneliness is sitting heavy today. Give yourself permission to feel it. Wrap up in a cozy blanket or hold a pillow and breathe with self-compassion for 5 minutes."},
        {"Psalm 23:4 - \"For you are with me...\"",
         "\"The most terrible poverty is loneliness and the feeling of being unloved.\" - Mother Teresa",
         "Isolation feels quiet and empty. That's valid. Try one small connection: send a quick \"thinking of you\" message or voice note."},
        {"Hebrews 13:5 - \"Never will I leave you; never will I forsake you.\"",
         "\"Loneliness and the feeling of being unwanted is the most terrible poverty.\" - Mother Teresa",
         "You're lonely and it hurts. Be kind to your heart. Play a song that feels like company or watch something comforting."},
        {"Matthew 28:20 - \"And surely I am with you always, to the very end of the age.\"",
         "\"Music was my refuge. I could crawl into the space between the notes and curl my back to loneliness.\" - Maya Angelou",
         "This isolated feeling is tough. You're not invisible. Look at a photo of loved ones or recall a warm memory for a moment."},
        {"Psalm 68:6 - \"God sets the lonely in families...\"",
         "\"Loneliness is my least favorite thing about life.\" - Anne Hathaway",
         "Loneliness whispers you're alone. Counter softly: say aloud \"I matter\" and take three deep breaths."},
        {"Psalm 25:16 - \"Turn to me and be gracious to me, for I am lonely and afflicted.\"",
         "\"Life is full of misery, loneliness, and suffering, and it's all over much too soon.\" - Woody Allen",
         "Feeling cut off right now. Bridge it tiny: open a window or step outside to hear life sounds."},
        {"Psalm 139:7-10 - \"Where can I go from your Spirit? ... You are there.\"",
         "\"Remember: the time you feel lonely is the time you most need to be by yourself. Life's cruelest irony.\" - Douglas Coupland",
         "The quiet is loud with loneliness. Fill it gently: talk to yourself kindly or journal one honest feeling."},
        {"Joshua 1:5 - \"I will never leave you nor forsake you.\"",
         "\"The loneliest moment in someone's life is when they are watching their whole world fall apart.\" - F. Scott Fitzgerald",
         "Isolated and unseen today. See yourself: look in mirror, smile softly, or say something affirming."},
        {"Romans 8:38-39 - \"Nothing will be able to separate us from the love of God...\"",
         "\"All great and precious things are lonely.\" - Various",
         "Loneliness aches in your chest. Soothe it: hug self tightly or cross arms while breathing warmth in."}
    }}
};

map<string, vector<string>> mood_suggestions = {
    {"Sad/Downcast", {"Acknowledge and Hydrate...", "Change Your Scenery...", "Low-Stakes Connection..."}},
    {"Anxious/Worried", {"The 5-4-3-2-1 Technique...", "The Brain Dump...", "Controlled Movement..."}},
    {"Unmotivated/Low Energy", {"The Five-Minute Rule...", "Sunlight Exposure...", "Micro-Win..."}},
    {"Grateful/Content", {"Specific Reflection...", "Pay It Forward...", "Savor the Moment..."}},
    {"Stressed/Overwhelmed", {"Box Breathing...", "Ruthless Prioritization...", "Digital Detox..."}},
    {"Lonely/Isolated", {"Passive Socializing...", "Voice Connection...", "Pursue a Solo Hobby..."}}
};

const string HISTORY_FILE = "mood_history.json";

// UTILITY 

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

string get_current_datetime() {
    time_t now = time(nullptr);
    struct tm* t = localtime(&now);
    char buf[20];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M", t);
    return string(buf);
}

// Simple random using Mersenne Twister
mt19937 rng(static_cast<unsigned>(time(nullptr)));

MoodPackage select_random_package(const string& mood) {
    auto& packages = mood_content.at(mood);
    uniform_int_distribution<size_t> dist(0, packages.size() - 1);
    return packages[dist(rng)];
}

// JSON HELPERS (minimal, no external lib) 

string escape_json(const string& s) {
    string out;
    for (char c : s) {
        if (c == '"')  out += "\\\"";
        else if (c == '\\') out += "\\\\";
        else if (c == '\n') out += "\\n";
        else if (c == '\r') out += "\\r";
        else if (c == '\t') out += "\\t";
        else out += c;
    }
    return out;
}

string unescape_json(const string& s) {
    string out;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == '\\' && i + 1 < s.size()) {
            char next = s[i + 1];
            if (next == '"')  { out += '"';  ++i; }
            else if (next == '\\') { out += '\\'; ++i; }
            else if (next == 'n')  { out += '\n'; ++i; }
            else if (next == 'r')  { out += '\r'; ++i; }
            else if (next == 't')  { out += '\t'; ++i; }
            else out += s[i];
        } else {
            out += s[i];
        }
    }
    return out;
}

// Extract value for a key from a simple JSON object line
string extract_json_value(const string& line, const string& key) {
    string search = "\"" + key + "\": \"";
    size_t pos = line.find(search);
    if (pos == string::npos) return "";
    pos += search.size();
    string val;
    for (size_t i = pos; i < line.size(); ++i) {
        if (line[i] == '\\' && i + 1 < line.size()) {
            val += line[i];
            val += line[i + 1];
            ++i;
        } else if (line[i] == '"') {
            break;
        } else {
            val += line[i];
        }
    }
    return unescape_json(val);
}

// HISTORY 

vector<HistoryEntry> load_history() {
    vector<HistoryEntry> history;
    ifstream f(HISTORY_FILE);
    if (!f.is_open()) return history;

    string line;
    HistoryEntry entry;
    bool in_object = false;
    while (getline(f, line)) {
        size_t start = line.find_first_not_of(" \t");
        if (start == string::npos) continue;
        line = line.substr(start);

        if (line == "{") {
            in_object = true;
            entry = {};
        } else if ((line == "}," || line == "}") && in_object) {
            if (!entry.date.empty()) history.push_back(entry);
            in_object = false;
        } else if (in_object) {
            string d = extract_json_value(line, "date");
            string m = extract_json_value(line, "mood");
            string n = extract_json_value(line, "note");
            if (!d.empty()) entry.date = d;
            if (!m.empty()) entry.mood = m;
            if (!n.empty()) entry.note = n;
        }
    }
    return history;
}

void save_history(const vector<HistoryEntry>& history) {
    ofstream f(HISTORY_FILE);
    if (!f.is_open()) return;
    f << "[\n";
    for (size_t i = 0; i < history.size(); ++i) {
        f << "  {\n";
        f << "    \"date\": \"" << escape_json(history[i].date) << "\",\n";
        f << "    \"mood\": \"" << escape_json(history[i].mood) << "\",\n";
        f << "    \"note\": \"" << escape_json(history[i].note) << "\"\n";
        f << "  }" << (i + 1 < history.size() ? "," : "") << "\n";
    }
    f << "]\n";
}

void log_entry(const string& mood, const string& note) {
    auto history = load_history();
    HistoryEntry e;
    e.date = get_current_datetime();
    e.mood = mood;
    e.note = note;
    history.push_back(e);
    save_history(history);
}

// DISPLAY FUNCTIONS 

void show_encouragement(const string& mood) {
    MoodPackage pkg = select_random_package(mood);
    cout << "   ENCOURAGEMENT FOR: ";
    cout<<endl;
    cout<<endl;
    for (char c : mood) cout << (char)toupper(c);
    cout<<endl;
    cout << "Verse:"<<endl;
    cout<< pkg.verse << endl;
    cout<<endl;
    cout << "Quote:"<<endl;
    cout << pkg.quote << endl;
    cout<<endl;
    cout << "Note:"<<endl;
    cout << pkg.message << endl;
    cout<<endl;
}

void save_current_entry(const string& mood) {
    if (mood.empty()) {
        cout << "\nPlease select a mood first!\n";
        return;
    }
    cout << "\nAdd a short note (optional, press Enter to skip):\n-> ";
    string note;
    getline(cin, note);
    size_t s = note.find_first_not_of(" \t");
    if (s != string::npos) note = note.substr(s);
    size_t e = note.find_last_not_of(" \t");
    if (e != string::npos) note = note.substr(0, e + 1);

    log_entry(mood, note);
    cout << "\n[OK] Entry saved successfully!\n\n";
}

void show_history() {
    auto history = load_history();
    if (history.empty()) {
        cout << "\nNo mood entries yet.\n";
        return;
    }

    string sep(85, '=');
    string thin(80, '-');
    cout << "\n" << sep << "\n";
    cout << "                          MOOD HISTORY (Newest First)\n";
    cout << sep << "\n";
    cout << "Total entries: " << history.size() << "\n\n";

    size_t start_idx = history.size() > 50 ? history.size() - 50 : 0;
    vector<HistoryEntry> recent(history.begin() + start_idx, history.end());
    reverse(recent.begin(), recent.end());

    for (size_t i = 0; i < recent.size(); ++i) {
        cout << setw(2) << (i + 1) << ". [" << recent[i].date << "]  ->  " << recent[i].mood << "\n";
        if (!recent[i].note.empty()) {
            string note = recent[i].note;
            if (note.size() > 130) note = note.substr(0, 130) + "...";
            cout << "     Note: " << note << "\n";
        }
        cout << thin << "\n";
    }

    cout << "\nOptions:\n";
    cout << "   d  -> Delete specific entries (e.g. 1,3,5)\n";
    cout << "   c  -> Clear entire history\n";
    cout << "   b  -> Back\n";
    cout << "\nEnter choice: ";

    string action;
    getline(cin, action);
    // Trim & lowercase
    size_t s = action.find_first_not_of(" \t");
    if (s != string::npos) action = action.substr(s);
    for (char& c : action) c = tolower(c);

    if (action == "d") {
        cout << "\nEnter numbers to delete (comma-separated): ";
        string nums_str;
        getline(cin, nums_str);
        if (nums_str.empty()) return;

        set<size_t> to_delete;
        stringstream ss(nums_str);
        string token;
        while (getline(ss, token, ',')) {
            size_t ts = token.find_first_not_of(" \t");
            if (ts != string::npos) token = token.substr(ts);
            size_t te = token.find_last_not_of(" \t");
            if (te != string::npos) token = token.substr(0, te + 1);

            bool is_num = !token.empty();
            for (char c : token) if (!isdigit(c)) { is_num = false; break; }
            if (!is_num) continue;

            int disp_idx = stoi(token);
            if (disp_idx >= 1 && disp_idx <= (int)recent.size()) {
                size_t real_idx = history.size() - (size_t)disp_idx;
                to_delete.insert(real_idx);
            }
        }

        if (to_delete.empty()) {
            cout << "No valid entries selected.\n";
            return;
        }

        cout << "Delete " << to_delete.size() << (to_delete.size() == 1 ? " entry" : " entries") << "? (y/n): ";
        string confirm;
        getline(cin, confirm);
        if (!confirm.empty() && tolower(confirm[0]) == 'y') {
            vector<HistoryEntry> new_history;
            for (size_t i = 0; i < history.size(); ++i) {
                if (to_delete.find(i) == to_delete.end())
                    new_history.push_back(history[i]);
            }
            save_history(new_history);
            cout << "[OK] Deleted " << to_delete.size() << (to_delete.size() == 1 ? " entry" : " entries") << " successfully.\n";
        }
    } else if (action == "c") {
        cout << "\nClear ALL history? (y/n): ";
        string confirm;
        getline(cin, confirm);
        if (!confirm.empty() && tolower(confirm[0]) == 'y') {
            save_history({});
            cout << "History cleared.\n";
        }
    }
}

void show_weekly_summary() {
    auto history = load_history();
    if (history.empty()) {
        cout << "\nNo entries yet.\n";
        return;
    }

    time_t now = time(nullptr);
    time_t seven_days_ago = now - 7 * 24 * 3600;

    vector<HistoryEntry> recent;
    for (auto& e : history) {
        struct tm t = {};
        sscanf(e.date.c_str(), "%d-%d-%d", &t.tm_year, &t.tm_mon, &t.tm_mday);
        t.tm_year -= 1900;
        t.tm_mon -= 1;
        t.tm_isdst = -1;
        time_t entry_time = mktime(&t);
        if (entry_time >= seven_days_ago) recent.push_back(e);
    }

    if (recent.empty()) {
        cout << "\nNo entries in the last 7 days.\n";
        return;
    }

    map<string, int> counts;
    for (auto& e : recent) counts[e.mood]++;
    int total = (int)recent.size();

    string dominant;
    int dominant_count = 0;
    for (auto& kv : counts) {
        if (kv.second > dominant_count) {
            dominant_count = kv.second;
            dominant = kv.first;
        }
    }
    double dominant_percent = total > 0 ? (dominant_count * 100.0 / total) : 0.0;

    string sep(85, '=');
    cout << "\n" << sep << "\n";
    cout << "                    WEEKLY EMOTIONAL SUMMARY\n";
    cout << sep << "\n";
    cout << "Total entries this week: " << total << "\n\n";

    int max_count = 0;
    for (auto& kv : counts) if (kv.second > max_count) max_count = kv.second;
    if (max_count == 0) max_count = 1;

    vector<string> mood_order = {
        "Sad/Downcast", "Anxious/Worried", "Unmotivated/Low Energy",
        "Grateful/Content", "Stressed/Overwhelmed", "Lonely/Isolated"
    };

    for (auto& mood : mood_order) {
        int count = counts.count(mood) ? counts.at(mood) : 0;
        if (count == 0) continue;
        double percent = (count * 100.0) / total;
        int bar_len = (int)((count * 40.0) / max_count);
        string bar(bar_len, '#');
        bar += string(40 - bar_len, '.');
        cout << left << setw(27) << mood << " "
                  << right << setw(3) << count
                  << "  " << bar << "  "
                  << fixed << setprecision(1) << percent << "%\n";
    }

    cout << "\n[*] Most frequent mood: " << dominant
              << " (" << fixed << setprecision(1) << dominant_percent << "%)\n";

    if (dominant_percent >= 50.0 && mood_suggestions.count(dominant)) {
        cout << "\n[!] Suggestions for " << dominant << ":\n";
        auto& suggestions = mood_suggestions.at(dominant);
        for (size_t i = 0; i < suggestions.size(); ++i)
            cout << "   " << (i + 1) << ". " << suggestions[i] << "\n";
    }
    cout << sep << "\n";
}

void print_header() {
    clear_screen();
    string sep(85, '=');
    cout << sep << "\n";
    cout << "                  MOODLIFT - Personalized Mood Tracker\n";
    cout << "                  Console Edition - All Moods Included\n";
    cout << sep << "\n\n";
}

void show_mood_menu() {
    cout << "How are you feeling right now?\n\n";
    vector<string> moods = {
        "Sad/Downcast", "Anxious/Worried", "Unmotivated/Low Energy",
        "Grateful/Content", "Stressed/Overwhelmed", "Lonely/Isolated"
    };
    for (size_t i = 0; i < moods.size(); ++i)
        cout << "  " << setw(2) << (i + 1) << ". " << moods[i] << "\n";
    cout << "\n   0. Exit\n";
    cout << "   w. Weekly Summary\n";
    cout << "   h. View History\n\n";
}

// MAIN 

int main() {
    cout << "Welcome to MoodLift Console\n";
    cout << "Press Enter to start...";
    cin.ignore(10000, '\n');

    vector<string> moods = {
        "Sad/Downcast", "Anxious/Worried", "Unmotivated/Low Energy",
        "Grateful/Content", "Stressed/Overwhelmed", "Lonely/Isolated"
    };

    while (true) {
        print_header();
        show_mood_menu();
        cout << "Enter your choice: ";
        string choice;
        getline(cin, choice);
        size_t s = choice.find_first_not_of(" \t");
        if (s != string::npos) choice = choice.substr(s);
        size_t e = choice.find_last_not_of(" \t");
        if (e != string::npos) choice = choice.substr(0, e + 1);
        for (char& c : choice) c = tolower(c);

        if (choice == "0") {
            cout << "\nThank you for using MoodLift. Take care <3\n";
            break;
        } else if (choice == "w") {
            show_weekly_summary();
            cout << "\nPress Enter to continue...";
            cin.ignore(10000, '\n');
        } else if (choice == "h") {
            show_history();
            cout << "\nPress Enter to continue...";
            cin.ignore(10000, '\n');
        } else if (choice.size() == 1 && choice[0] >= '1' && choice[0] <= '6') {
            int idx = choice[0] - '1';
            string mood = moods[idx];
            show_encouragement(mood);

            cout << "What would you like to do?\n";
            cout << "1. Save this entry\n";
            cout << "2. Choose another mood\n";
            cout << "3. Weekly summary\n";
            cout << "4. View history\n";
            cout << "5. Main menu\n";
            cout << "\nChoice: ";

            string action;
            getline(cin, action);
            size_t as = action.find_first_not_of(" \t");
            if (as != string::npos) action = action.substr(as);

            if (action == "1") {
                save_current_entry(mood);
                cout << "\nPress Enter to continue...";
                cin.ignore(10000, '\n');
            } else if (action == "3") {
                show_weekly_summary();
                cout << "\nPress Enter to continue...";
                cin.ignore(10000, '\n');
            } else if (action == "4") {
                show_history();
                cout << "\nPress Enter to continue...";
                cin.ignore(10000, '\n');
            }
        } else {
            cout << "\nInvalid choice.\n";
            cout << "\nPress Enter to continue...";
            cin.ignore(10000, '\n');
        }
    }

    return 0;
}