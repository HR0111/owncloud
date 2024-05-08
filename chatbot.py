def elementary_chatbot():
    print("Welcome to Customer Interaction Chatbot!")

    while True:
        user_input = input("You: ").lower()

        # Define responses based on user input
        if "hello" in user_input:
            print("Chatbot: Hi there! How can I assist you today?")
        elif "how are you" in user_input:
            print("Chatbot: I'm just a chatbot, but thanks for asking!")
        elif "order" in user_input:
            print("Chatbot: To place an order, please visit our website or contact our sales team.")
        elif "shipping" in user_input:
            print("Chatbot: For shipping inquiries, please contact our support team.")
        elif "payment" in user_input:
            print("Chatbot: For payment-related questions, please visit our FAQ page.")
        elif "thank you" in user_input:
            print("Chatbot: You're welcome! Is there anything else I can assist you with?")
        elif "bye" in user_input:
            print("Chatbot: Goodbye! Have a great day!")
            break
        else:
            print("Chatbot: I'm sorry, I didn't understand that. Could you please rephrase your question?")

if __name__ == "__main__":
    elementary_chatbot()