import re

def chatbot_response(user_input):
    # Dictionary of pattern-response pairs
    responses = {
        r'hi|hello|hey': "Hello! How can I help you today?",
        r'how are you|how are you doing': "I'm just a bot, but I'm doing great! How about you?",
        r'what is your name': "I'm ChatBot! What's your name?",
        r'my name is (.*)': "Nice to meet you, {0}!",
        r'bye|exit|quit': "Goodbye! Have a great day!",
        r'(.*)': "I'm sorry, I don't quite understand that. Can you rephrase?"
    }
    
    # Loop through patterns and find a match
    for pattern, response in responses.items():
        match = re.search(pattern, user_input.lower())
        if match:
            # Format response with captured groups
            return response.format(*match.groups())
    return "I didn't understand that."

def main():
    print("ChatBot: Hello! I'm here to assist you. Type 'bye' to exit.")
    while True:
        user_input = input("You: ")
        if user_input.lower() in ['bye', 'exit', 'quit']:
            print("ChatBot: Goodbye! Have a great day!")
            break
        response = chatbot_response(user_input)
        print(f"ChatBot: {response}")

if __name__ == "__main__":
    main()
