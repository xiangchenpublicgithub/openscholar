Feature:
  Testing the RSS feed widget.

  @api @last
  Scenario: Verify the RSS feed widget works fine.
     Given I am logging in as "john"
       And the widget "RSS feed" is set in the "Classes" page with the following <settings>:
           | Show all content   | uncheck   | checkbox  |
           | Bio                | check     | checkbox  |
           | Blog entry         | check     | checkbox  |
       And I visit "john/classes"
      Then I should see "RSS feed"
       And I should see the link "Subscribe"
